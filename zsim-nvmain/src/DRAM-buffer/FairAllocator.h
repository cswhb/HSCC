/*
 * 2015-xxx by YuJie Chen
 * email:    YuJieChen_hust@163.com
 * function: extend zsim-nvmain with some other simulation,such as tlb,page table,page table,etc.
 */
#ifndef _Fair_Allocator_H_
#define _Fair_Allocator_H_
#include <math.h>
#include "g_std/g_vector.h"
#include "g_std/g_list.h"
#include "g_std/g_unordered_set.h"
#include "memory_hierarchy.h"
#include "DRAM-buffer/DRAM_buffer_block.h"
<<<<<<< HEAD
#include "tlb/page_table_walker.h"//cswhb added
=======
>>>>>>> parent of c6a8249... before change allocate_one_page
#include "MMU/memory_management.h"  //cswhb added
class FairAllocator: public BaseDRAMBufferManager 
{
	public:
		FairAllocator( unsigned proccess_num , 
					   Address memory_size);
		
		unsigned Release( unsigned process_id , unsigned evict_size );
<<<<<<< HEAD
		DRAMBufferBlock* allocate_one_page( PageTableWalker<ExtendTlbEntry>*p,MemReq& req, DRAMBufferBlock* dram_block,BaseTlbEntry* entry, uint32_t core_id, bool &evict,uint64_t page_shift,unsigned process_id );
=======
		DRAMBufferBlock* allocate_one_page( unsigned process_id );
>>>>>>> parent of c6a8249... before change allocate_one_page
		void convert_to_dirty( unsigned process_id , Address block_id);  
		double get_memory_usage();
		bool should_reclaim();
		void evict( DRAMEVICTSTYLE policy);
		bool should_cherish();
		bool should_more_cherish();
		virtual DRAMBufferBlock* get_page_ptr( uint64_t entry_id );
		BuddyAllocator* DRAM_buddy_allocator;//cswhb added
		MemoryNode* DRAM_mem_node;//cswhb added
	private:
		void fairness_evict();
		void equal_evict();
	private:
		unsigned process_count;
		Address memory_capacity;
		Address total_page_count;
		Address busy_pages;

		uint64_t min_free_pages;
		g_vector<int> proc_busy_pages;
		g_vector<g_unordered_set<Address> > clean_pools;
		g_vector<g_unordered_set<Address> > dirty_pools;

		lock_t pool_lock;

		g_list<Address> global_clean_pool;	
		g_list<Address> global_dirty_pool;
		
		g_vector<DRAMBufferBlock*> buffer_array;
};
#endif
