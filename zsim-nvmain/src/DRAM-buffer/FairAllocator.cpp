/*
 * 2015-xxx by YuJie Chen
 * email:    YuJieChen_hust@163.com
 * function: extend zsim-nvmain with some other simulation,such as tlb,page table,page table,etc.
 */
#include "DRAM-buffer/FairAllocator.h"
#include "zsim.h"
FairAllocator::FairAllocator( unsigned process_num , 
				Address memory_size): process_count(process_num),
									  memory_capacity( memory_size ), busy_pages(0)
{
	total_page_count = memory_size >> (zinfo->page_shift);
	//create descriptors for all pages
	for( Address i = 0; i < total_page_count; i++ )
	{
		 DRAMBufferBlock* block = new DRAMBufferBlock(i); 
		 block->block_shift=12;
		 block->page->NULL;
		 buffer_array.push_back( block );	
		 global_clean_pool.push_back(i);
	}
	global_dirty_pool.clear();

	//for recording process taken space
	for( unsigned i=0 ; i<process_count; i++ )
	{
		g_unordered_set<Address> tmp;
		clean_pools.push_back(tmp);
		dirty_pools.push_back(tmp);
	}
	proc_busy_pages.resize(process_count);
	uint64_t max_pages=((uint64_t)2<<26);
	uint64_t min_pages = ((uint64_t)2<<17);
	//calculate min free pages
	min_free_pages = Min( Max((uint64_t)(4*sqrt(memory_size)),min_pages),max_pages);
	std::cout<<"min free pages:"<<std::hex<<min_free_pages<<std::endl;
	std::cout<<"min pages:"<<std::hex<<min_pages<<std::endl;
	std::cout<<"max pages:"<<std::hex<<max_pages<<std::endl;
	//min free page num
	min_free_pages /=(zinfo->page_size);
	
	//cswhb added buddyallocator
	MemoryNode* mem_node = gm_memalign<MemoryNode>(CACHE_LINE_BYTES , 1);
    DRAM_mem_node = new (mem_node) MemoryNode(3,0);
    DRAM_mem_node->reset_zone(1<<18);
    BuddyAllocator* buddy = gm_memalign<BuddyAllocator>(CACHE_LINE_BYTES , 1);
	DRAM_buddy_allocator = new (buddy) BuddyAllocator(zinfo->memory_node);
	
	futex_init(&pool_lock);
}

bool FairAllocator::should_reclaim()
{
	if( total_page_count - busy_pages == 1)
		return true;
	return false;
}

bool FairAllocator::should_cherish()
{
	if( total_page_count - busy_pages <= 0.3*total_page_count)
		return true;
	return false;
}

bool FairAllocator::should_more_cherish()
{
	Address free_pages = total_page_count - busy_pages;
	if( free_pages <=0.05*total_page_count || free_pages <= min_free_pages)
	{
		return true;
	}
	return false;
}

unsigned FairAllocator::Release(BasePageTableWalker*p,MemReq& req, DRAMBufferBlock* dram_block,T* entry, uint32_t core_id, bool &evict,unsigned process_id, unsigned evict_size )
{
	futex_lock(&pool_lock);
	//evict clean page firs<<std::endl;t
	uint64_t shift;//cswhb added
	unsigned order;
	unsigned busy_dre=0;
	unsigned clean_pool_size = clean_pools[process_id].size();
	unsigned clean_evict_size = (evict_size > clean_pool_size)? clean_pool_size:evict_size;
	assert( clean_pool_size + dirty_pools[process_id].size()>= evict_size);
	//reclaim clean pages
	for( unsigned i=0 ; i < clean_evict_size; )
	{
		//if( *clean_pools[proc].)
		Address block_id = *clean_pools[process_id].begin();
		//cswhb modified
		shift=buffer_array[block_id];
		order=shift-12;
		for(uint64_t j=0,t=(block_id>>(shift-12))<<(shift-12);j<(1<<(shift-12));j++,t++){
			if(clean_pools[process_id].count(t)==0){
				info("FairAllocator:error in Release"); 
			}
			else{
				clean_pools[process_id].erase(t );
				((PageTableWalker<ExtendTlbEntry>*)p)->evict_DRAM_page( req,buffer_entry[t] ,entry, coreId, evict);
		    	global_clean_pool.push_back(t);
				busy_pages--;
				busy_dre++;
				i++;
			}
			DRAM_buddy_allocator->free_pages(0,buffer_array[(block_id>>(shift-12))<<(shift-12)]->page_no,order);
		}
		
	}
	if( clean_evict_size < evict_size)
	{
		//std::cout<<"evict dirty pages"<<std::endl;
		//evict dirty pages
		for( unsigned i = 0 ; i < (evict_size-clean_evict_size); )
		{
			Address block_id = *dirty_pools[process_id].begin();
			shift=buffer_array[block_id];
		    order=shift-12;
		    for(uint64_t j=0,t=(block_id>>(shift-12))<<(shift-12);j<(1<<(shift-12));j++,t++){
			    if(dirty_pools[process_id].count(t)==0){
				    info("FairAllocator:error in Release"); 
			    }
			    else{
				    dirty_pools[process_id].erase(t );
		    	    global_dirty_pool.push_back(t);
		    	    ((PageTableWalker<ExtendTlbEntry>*)p)->evict_DRAM_page( req,buffer_entry[t] ,entry, coreId, evict);
				    busy_pages--;
				    busy_dre++
				    i++
			    }
			    DRAM_buddy_allocator->free_pages(0,buffer_array[(block_id>>(shift-12))<<(shift-12)]->page_no,order);
		    }
		}
	}
	proc_busy_pages[process_id] -= busy_dre;
	assert(should_reclaim()==false);
	futex_unlock(&pool_lock);
	return evict_size;	
}

double FairAllocator::get_memory_usage() 
{
	return (double)busy_pages/(double)total_page_count;
}
//cswhb modified
DRAMBufferBlock* FairAllocator::get_page_ptr( uint64_t entry_id )
{
	bool check = false;
	for( uint32_t i = 0; i < zinfo->numProcs; i++)
	{
		if( clean_pools[i].count(entry_id) || dirty_pools[i].count(entry_id))
		{
			if(buffer_array[entry_id]->block_shift==12){
				check = true;
				break;
			}
		}
		if(clean_pools[i].count((entry_id>>5)<<5) || dirty_pools[i].count((entry_id>>5)<<5)){
			if(buffer_array[entry_id]->block_shift==17){
				check = true;
				break;
			}
		}
		if(clean_pools[i].count((entry_id>>10)<<10) || dirty_pools[i].count((entry_id>>10)<<10)){
			if(buffer_array[entry_id]->block_shift==22){
				check = true;
				break;
			}
		}
	}
	if( check )
		return buffer_array[entry_id];
	return NULL;
}
//cswhb modified   return NULL when buddy_alloc failed
DRAMBufferBlock* FairAllocator::allocate_one_page( BasePageTableWalker*p,MemReq& req, DRAMBufferBlock* dram_block,T* entry, uint32_t core_id, bool &evict,uint64_t page_shift,unsigned process_id )
{
	futex_lock(&pool_lock);
	unsigned order,index;//cswhb added
	assert(!global_clean_pool.empty()|| !global_dirty_pool.empty())
	Address alloc_block_id = INVALID_PAGE_ADDR;
	DRAMEVICTSTYLE policy=Equal;
	//cswhb modified
	Page*page=DRAM_buddy_allocator->allocate_pages(0,0,page_shift);
	while(!page){
		for( uint32_t i=0; i< process_count; i++)
	    {
		    proc_busy_size = clean_pools[i].size()+dirty_pools[i].size();
		    if( proc_busy_size > 0)
		    {
			    Release(p,req,dram_block,entry,core_id,evict, i, 1);
		    }
	    }
		page=DRAM_buddy_allocator->allocate_pages(0,0,page_shift);
	}
	if(!buffer_array.count(page->pageNo)){
		info("FairAllocator error in allocate_one_page");
		futex_unlock(&pool_lock);
		return NULL;
	}
	buffer_array[page->pageNo]->block_shift=page->page_shift;
	buffer_array[page->pageNo]->page=(void*)page;
	order=page->page_shift-12;
	index=(page->pageNo>>(order))<<(order);
	for(uint64_t i=0;i<(1<<order);i++){
		if(global_clean_pool.count(index)){
			global_clean_pool.erase(index);
		}
		else if(global_dirty_pool.count(index)){
			global_dirty_pool.erase(index);
		}
		else{
			info("FairAllocator error in allocate_one_page:global");
		    futex_unlock(&pool_lock);
		    return NULL;
		}
		buffer_array[index]->block_shift=page->page_shift;
	    buffer_array[index]->page=(void*)page;
		clean_pools[process_id].insert(index);
		busy_pages++;
		proc_busy_pages[process_id]++;
		index++;
	}
	futex_unlock(&pool_lock);
	return buffer_array[(page->pageNo>>(order))<<(order)];
}

/*
 * @function:
 * @param:
 */
 //cswhb modified
void FairAllocator::convert_to_dirty( unsigned process_id , Address block_id )
{
	futex_lock(&pool_lock);
	unsigned index=0;
	uint64_t order=0;
	if( clean_pools[process_id].find(block_id) == clean_pools[process_id].end())
	{
		futex_unlock(&pool_lock);
		return;
	}
	else
	{
		order=buffer_entry[block_id]->block_shift-12;
		index=(block_id>>order)<<order;
		for(uint64_t i=0;i<(1<<order);i++){
			if( clean_pools[process_id].find(index) == clean_pools[process_id].end())
	        {
	        	info("FairAllocator :converty_to_dirty error");
		        futex_unlock(&pool_lock);
		        return;
	        }
	        else{
	        	clean_pools[process_id].erase(index);
		        dirty_pools[process_id].insert(index);
			}
			index++;
			
		}
	}
	futex_unlock(&pool_lock);
}

void FairAllocator::evict(BasePageTableWalker*p,MemReq& req, DRAMBufferBlock* dram_block,T* entry, uint32_t core_id, bool &evict,DRAMEVICTSTYLE policy)
{
	assert( should_reclaim());
	return equal_evict(p,req,dram_block,entry,core_id,evict);
}

/*
 *@function:
 *@param:
 */
void FairAllocator::equal_evict(PageTableWalker<ExtendTlbEntry>*p,MemReq& req, DRAMBufferBlock* dram_block,T* entry, uint32_t core_id, bool &evict  )
{
	int reclaim_pages = min_free_pages-(total_page_count-busy_pages);
	//reclaim equally
	double rate;		
	Address proc_busy_size;
	Address release_size;
	for( uint32_t i=0; i< process_count; i++)
	{
		proc_busy_size = clean_pools[i].size()+dirty_pools[i].size();
		if( proc_busy_size > 0)
		{
			rate = (double)proc_busy_size/total_page_count;
			release_size = (int)(rate*reclaim_pages)+1;
			Release(p,req,dram_block,entry,core_id,evict, i, release_size);
		}
	}
}

void FairAllocator::fairness_evict()
{
}
