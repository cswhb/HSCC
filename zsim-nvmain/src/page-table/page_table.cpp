







































































	
								write_back,access_counter );
						debug_printf("remove %d entry of page table failed!",i);
						remove_page_table( pml4_entry_id , pdp_entry_id , i);
						set_dirty, write_back, access_counter);
						succeed = false;
						succeed = false;
					if( is_present(pd_table , i))
					if( remove_page_directory(pml4_entry_id , i)==false)
					if(remove_page_table(pdp_entry_id ,i)==false)
					{
					}
				//get page directory
				alloc_time++;
				alloc_time++;
				cur_pdt_num--;
				cur_pt_num++;
				cur_pt_num++;
				cur_pt_num--;
				debug_printf("remove (page directory pointer,page directory)-(%d,%d) pointed page table failed",page_dir_ptr,page_dir+i);
				debug_printf("remove page directory entry %d of page direcotry pointer pointed to failed", i);
				for(unsigned i=0 ; i<ENTRY_512;i++)
				if( is_present( page_dir ,i))
				if( is_present(pdp_table,i))
				invalidate_entry<PageTable>(pd_table , pd_entry_id);
				mapped_entry = (*table)[pd];
				mapped_entry = (*table)[pd_id];
				mapped_entry = (*table)[pdp];
				PageTable* page_dir = get_next_level_address<PageTable>( pdp_table , pdpt_entry_id);
				PageTable* pg_table=new (table)PageTable(ENTRY_512);
				PageTable* table = get_next_level_address<PageTable>(pd_table,pdt_entry_id);
				PageTable* table = new (table_tmp)PageTable(ENTRY_512);
				PageTable* table= gm_memalign<PageTable>( CACHE_LINE_BYTES, 1);
				PageTable* table_tmp= gm_memalign<PageTable>( CACHE_LINE_BYTES, 1);
				remove_page_directory_pointer(i);
				return pg_table;
				return table;
				return table;
				set_dirty, write_back ,access_counter);
				succeed = false;
				succeed = true;
				validate_entry(page_dir , pdt_entry_id , pg_table );
				validate_entry(pd_table , pdt_entry_id ,table );
				{
				{
				}
				}
			 invalidate_page( pt_ptr , pt_id );
			 return true;
			 unsigned pt_id = get_pagetable_off(addr,mode);
			//	mapped_entry = (*page_directory)[pd_entry_id];
			//	mapped_entry = (*table)[pt];
			//	mapped_entry = (*table)[pt_entry_id];
			//debug_printf("validate entry %d",pt_entry_id);
			//delete presented page table
			//extend_one_buffer_map(addr , table , pg_ptr , pt_id , buffer_entry_id , buffer_table_entry_num, mapped_entry);			
			//extend_one_buffer_map(addr ,page_directory,pg_ptr,pd_entry_id ,buffer_entry_id, buffer_table_entry_num, mapped_entry);
			//extend_one_buffer_map(addr,table,pg_ptr , pt, buffer_entry_id, buffer_table_entry_num, mapped_entry);
			//extend_one_buffer_map(addr,table,pg_ptr , pt_entry_id ,buffer_entry_id, buffer_table_entry_num, mapped_entry);
			//if( !is_valid(page_directory, pd_entry_id) )
			//if( !is_valid(table, pt) )	
			//if( !is_valid(table, pt_entry_id) )
			//main memory block size is equal to buffer block size
			//new page table 
			//std::cout<<"extend one buffer map"<<std::endl;
			//std::cout<<"validate "<<pd_entry_id<<" end"<<std::endl;
			//std::cout<<"validate "<<pd_entry_id<<std::endl;
			//std::cout<<req.lineAddr<<" point to dram buffer:"<<pbuffer<<std::endl;
			allocate_time += 1;
			allocate_time = 1;
			allocate_time++;
			cur_page_table_num--;
			cur_pd_num++;
			cur_pd_num++;
			cur_pd_num--;
			cur_pdp_num--;
			cur_pdt_num--;
			cur_pt_num++;
			cur_pt_num--;
			debug_printf("allocate %d page table for 0x%x failed",page_num , addr);
			debug_printf("allocate (pml4_entry_id , page directory pointer entry id)---(%d,%d) failed",(*it).first , (*it).second );
			debug_printf("allocate number of %d page directory for address 0x%x failed",page_dir_num , addr);
			debug_printf("allocate page directory failed !");
			debug_printf("allocate page directory for %d entry of page directory pointer failed",*it);
			debug_printf("allocate page directory for entry %d for page directory pointer failed");
			debug_printf("allocate page directory for LongMode_Middle failed!");
			debug_printf("allocate page directory pointer for entry %d of pml4 table failed",*it);
			debug_printf("allocate page directory pointer for LongMode_Huge failed!");
			debug_printf("allocate page table failed");
			debug_printf("allocate page table for %d th entry failed",base_entry_id+i);
			debug_printf("allocate page table for LongMode_Normal failed!");
			debug_printf("didn't find entry indexed with %ld !",addr);
			debug_printf("didn't find entry indexed with %ld !",addr);
			debug_printf("didn't find entry indexed with %ld !",addr);
			debug_printf("entry %d of page directory is invalid", pd_num);
			debug_printf("entry to be invalidate of TLB isn't valid!");
			debug_printf("remove page directory pointed by entry %d of page directory pointer failed", *it);
			debug_printf("remove page directory whose arrange is (%ld,%ld) failed",addr , addr+size);
			debug_printf("remove page table for (page direcotor pointer entry id: %d , page directory id:%d) failed",(*it).first , (*it).second);
			debug_printf("remove page table of %d th entry of page directory failed", base_pageNo+page_num);
			else
			extend_one_buffer_map(addr , table , pg_ptr , pd , buffer_entry_id , buffer_table_entry_num, mapped_entry);
			extend_one_buffer_map(addr , table ,pg_ptr, pdp,buffer_entry_id , buffer_table_entry_num, mapped_entry);
			extend_one_buffer_map(addr,table, pg_ptr , pd_id, buffer_entry_id , buffer_table_entry_num, mapped_entry);
			for( i=0 ; i<ENTRY_512; i++)
			for(unsigned i=0;i<ENTRY_512;i++)
			get_next_level_address<PageTable>(page_directory , pd_entry_id);
			if( !is_valid(table, pd) )
			if( !is_valid(table, pd_id) )
			if( !is_valid(table, pdp) )
			if( (pg_table=get_next_level_address<PageTable>(pd_table, pd_entry_id)) )
			if( allocate_page_directory(pml4_entry_id,pdpt_entry_id, alloc_time))
			if( i== ENTRY_512 )
			if( pt_ptr )
			if( remove_pdt(i)==false )
			if(is_present(pd_table , pdt_entry_id))
			if(is_present(pml4,i))
			if(mode==LongMode_Normal)
			if(remove_page_table(page_dir_ptr , page_dir+i)==false)
			invalidate_entry<PageTable>( page_dir , pd_num );
			invalidate_entry<PageTable>( page_directory_pointer,pdp_entry_id);
			invalidate_entry<PageTable>(page_directory, pd_entry_id);
			invalidate_entry<PageTable>(pdp_table,pdp_entry_id);
			invalidate_entry<PageTable>(pml4,pml4_entry_id);
			invalidate_page(pd_ptr , pd_id);
			mapped_entry = (*page_directory)[pd_entry_id];
			mapped_entry = (*table)[pd];
			mapped_entry = (*table)[pd_id];
			mapped_entry = (*table)[pdp];
			mapped_entry = (*table)[pt];
			mapped_entry = (*table)[pt_entry_id];
			mapped_entry = (*table)[pt_id];
			page = new PageTable(ENTRY_512);
			PageTable* pd_table = new (table_tmp) PageTable(ENTRY_512);
			PageTable* pd_table=new (table_tmp)PageTable(ENTRY_512);
			PageTable* pdpt_table = get_next_level_address<PageTable>(pml4,pml4_entry_id);
			PageTable* pg_table = NULL;
			PageTable* pt_ptr = get_next_level_address<PageTable>(pd_ptr , pd_id);
			PageTable* table = get_next_level_address<PageTable>( pdp_table, pdpt_entry_id);
			PageTable* table_tmp= gm_memalign<PageTable>( CACHE_LINE_BYTES, 1);
			PageTable* table_tmp= gm_memalign<PageTable>( CACHE_LINE_BYTES, 1);
			pbuffer = point_to_buffer_table((PageTable*)ptr,pt_id);
			return false;
			return false;
			return false;
			return false;
			return false;
			return false;
			return false;
			return false;
			return false;
			return false;
			return false;
			return NULL;
			return PAGE_FAULT_SIG;
			return PAGE_FAULT_SIG;
			return PAGE_FAULT_SIG;
			return PAGE_FAULT_SIG;
			return PAGE_FAULT_SIG;
			return PAGE_FAULT_SIG;
			return pd_table;
			return pd_table;
			return table;
			return true;
			succeed = false;
			succeed = false;
			succeed = false;
			succeed = false;
			succeed = false;
			succeed = false;
			succeed = false;
			succeed = false;
			succeed = false;
			succeed = false;
			succeed = false;
			succeed = false;
			succeed = true;
			succeed = true;
			succeed = true;
			succeed= false;
			unsigned i=0;
			validate_entry( table , pd_id , pg_ptr);
			validate_entry( table,pd, pg_ptr);
			validate_entry(page_directory,pd_entry_id, pg_ptr, false);	
			validate_entry(page_directory,pd_entry_id, pg_ptr, true);	
			validate_entry(pdp_table , pdpt_entry_id , pd_table);
			validate_entry(pdpt_table , pdpt_entry_id , pd_table);
			validate_entry(table , pd_entry_id, page);
			validate_entry(table , pt , pg_ptr);
			validate_entry(table , pt , pg_ptr, true);
			validate_entry(table , pt_entry_id , pg_ptr , false);
			validate_entry(table , pt_entry_id , pg_ptr , true);
			validate_entry(table , pt_id ,pg_ptr);	
			validate_entry(table , pt_id ,pg_ptr, pbuffer);	
			validate_entry(table,pdp,pg_ptr);
			zinfo->page_shift = 12;	
			zinfo->page_shift=22;
			zinfo->page_size = 4*power(2,10);	//4KB
			zinfo->page_size = 4*power(2,20);
			{
			{
			{
			{
			{
			{
			{
			{
			{
			{
			{
			{	
			}
			}
			}
			}
			}
			}
			}
			}
			}
			}
			}
			}
		 it!= pdpt_entry.end();it++ )
		/*
		/*
		/*
		/*
		/*
		/*if( pbuffer )
		/*if(pbuffer)
		//		mapped_entry = (*table)[pt_id];
		//	if( !is_valid(table, pt_id) )
		//allocate page directory
		//connect page directory pointer with page directory
		//connect page directory with page table
		//else
		//if( pbuffer )
		//page directory
		//page directory
		//page or buffer table
		//page table 
		//page table already exist
		//page table offset
		//page_direcory doesn't exist allocate
		//point to buffer table or page 
		//point to page
		//point to page or buffer table 
		//point to page table
		//second access memory get page directory address
		//std::cout<<"new page  table"<<std::endl;
		//std::cout<<"validate page directory table in pg dir pointer"<<std::dec<<pdpt_entry_id<<std::endl;
		//std::cout<<"validate pg dir pointer in pml4"<<std::dec<<pml4_entry_id<<std::endl;
		//std::cout<<"validate: "<<std::dec<<pml4_entry_id<<","<<std::dec<<pdpt_entry_id<<","<<std::dec<<pdt_entry_id<<std::endl;
		//std::cout<<req.lineAddr<<"point to dram buffer:"<<pbuffer<<std::endl;
		//std::cout<<req.lineAddr<<"point to dram buffer:"<<pbuffer<<std::endl;
		//{
		//{
		//}
		access_counter = req.childId;
		access_counter = req.childId;
		access_counter = req.childId;
		alloc_time += 1;
		alloc_time += 3;
		allocate_time += 2;
		allocate_time = 1;
		allocate_time++;
		assert( (pd!=(unsigned)(-1)) &&(pt!=(unsigned)(-1)));
		assert( *it < ENTRY_1024 );
		assert( cur_page_table_num<= 1024 && mode==Legacy_Normal);
		assert( pd_id != (unsigned)(-1) );
		assert( pd_id != (unsigned)(-1));
		assert( pt_id != (unsigned)(-1));
		assert(zinfo);
		BasePDTEntry*& mapped_entry)
		buffer_table_entry_num = zinfo->page_size/zinfo->block_size;
		buffer_table_shift = zinfo->page_shift - zinfo->block_shift;
		cur_page_table_num++;
		cur_pd_num++;
		cur_pdp_num++;
		cur_pdp_num++;
		cur_pdt_num++;
		cur_pt_num++;
		cur_pt_num++;
		cur_pt_num++;	
		debug_printf("address must align with 2MB");
		debug_printf("create legacy paging succeed");
		debug_printf("create legacy paging");
		debug_printf("entry %d of page direcotry pointer pointed to nothing", pdp_entry_id);
		debug_printf("entry %d of page directory pointer is invalid",pdpt_num);
		debug_printf("map address:(%x,%x)",addr);
		debug_printf("point to dram buffer: %d",pbuffer);
		debug_printf("zinfo->block size is: %d",zinfo->block_size);
		delete pml4;
		else
		else
		else
		else
		else
		else
		else
		else
		else
		else if( mode == PAE_Huge)
		else if( mode == PAE_Normal)
		else if(select == Legacy_Huge)
		fatal("addr must align with 1GB");
		fatal("address must align wit 4M");
		fatal("address must align with 4M");
		fatal("base address must align with 1GB when allocate page directory in PAE mode");
		fatal("base address must align with 1MB");
		fatal("base address must be align with 1MB");
		fatal("must align with 2MB");
		for( unsigned i=0 ; i<ENTRY_512;i++ )
		for( unsigned i=0 ; i<page_table_num;i++)
		futex_init(&table_lock);
		i++;
		if (allocate_page_table( pdp_offset ,i+pd_offset, time)==false)
		if( !(allocate_page_table((*it).first , (*it).second), time) )
		if( !(allocate_pdt(*it, time)))
		if( !(remove_page_table(base_pageNo+page_num)))
		if( !allocate_one_pagetable(*it, allocate_time) )
		if( !allocate_one_pagetable(base_entry_id+i,allocate_time))
		if( !allocate_page_table((*it).first , (*it).second,(*it).third, time))
		if( !is_valid(page_directory, pd_entry_id) )
		if( !is_valid(table, pd) )
		if( !is_valid(table, pd_id) )
		if( !is_valid(table, pdp) )
		if( !is_valid(table, pt) )	
		if( !is_valid(table, pt_entry_id) )
		if( !is_valid(table, pt_id) )
		if( !page)
		if( !ptr )
		if( !ptr )
		if( !ptr )
		if( !ptr )
		if( !ptr )
		if( !ptr )
		if( !table )
		if( !table )
		if( !table )
		if( !table )
		if( !table )
		if( !table)
		if( (pd_table=get_next_level_address<PageTable>(pdp_table , pdp_entry_id)) )
		if( (pd_table=get_next_level_address<PageTable>(pdp_table,pdp_entry_id)) )
		if( (table = allocate_page_table(pdp_id , pd_id, allocate_time))==NULL )
		if( (table=allocate_pdt(pdp_id, allocate_time))==NULL)
		if( allocate_page_directory((*it).first,(*it).second, allocate_time)==false)
		if( allocate_page_directory_pointer(*it, allocate_time)==false)
		if( allocate_page_table(pml4_entry , pdp_entry , pd_entry+i, time)==false)
		if( allocate_pdt(base_addr+i, time)==false)
		if( is_buffer)
		if( is_buffer)
		if( is_present(page_dir , pd_num))
		if( is_present(page_directory_pointer , i))
		if( mode == PAE_Huge)
		if( mode == PAE_Normal)
		if( mode!=LongMode_Huge)
		if( pbuffer)
		if( pbuffer)
		if( ptr )
		if( remove_page_directory_pointer(*it))
		if( remove_pdt(*it)==false)
		if( remove_pdt(page_dir_ptr+i) )
		if( select == Legacy_Normal)
		if( table )
		if(!is_present(pdp_table , pdpt_entry_id))
		if(!table)
		if(!table)
		if(!table)
		if(allocate_page_directory_pointer(pml4_entry_id, allocate_time))
		if(page_directory)
		if(pd_table)
		if(remove_page_table( (*it).first , (*it).second) == false)
		invalidate_page( page_directory , pd_entry_id);		
		invalidate_page( table , pt_id );
		invalidate_page( table,pd_id);
		invalidate_page(table,pdp_id);
		invalidate_page(table,pt_id);
		it!=pdt_entry.end();it++)
		level--;
		page = get_next_level_address<PageTable>(table,pd_entry_id);
		page = new PageTable(ENTRY_512);
		page_dir=new PageTable(ENTRY_512);
		page_directory = new(table)PageTable(ENTRY_1024);
		PageTable* g_tables = gm_memalign<PageTable>(CACHE_LINE_BYTES,3);
		PageTable* pd_table = NULL;
		PageTable* pd_table=get_next_level_address<PageTable>(pdp_table , pdpt_entry_id);
		PageTable* pd_table=new (&g_tables[1])PageTable(ENTRY_512);
		PageTable* pd_table=NULL;
		PageTable* pdp_table=new (&g_tables[0])PageTable(ENTRY_512);
		PageTable* pg_table=new (&g_tables[2])PageTable(ENTRY_512);
		PageTable* table = allocate_one_pagetable( pd_entry_id, allocate_time );
		PageTable* table = new (table_tmp) PageTable(ENTRY_512);
		PageTable* table = NULL;
		PageTable* table= gm_memalign<PageTable>( CACHE_LINE_BYTES, 1);
		PageTable* table_tmp= gm_memalign<PageTable>( CACHE_LINE_BYTES, 1);
		pbuffer = point_to_buffer_table( (PageTable*)pdp_ptr,pdp_id);
		pbuffer = point_to_buffer_table( (PageTable*)ptr,pg_id);
		pbuffer = point_to_buffer_table( (PageTable*)ptr,pg_off);
		pbuffer = point_to_buffer_table((PageTable*)ptr,pd_id);
		pbuffer = point_to_buffer_table((PageTable*)ptr,pd_id);
		pbuffer = point_to_buffer_table((PageTable*)ptr,pg_dir_off);
		pg_id = pd_id;
		pg_id = pg_dir_off;
		pg_id = pg_off;
		pgt = (PageTable*)page_directory_pointer;
		pgt = (PageTable*)ptr;
		pgt = (PageTable*)ptr;
		pgt = (PageTable*)ptr;
		pgt = (PageTable*)ptr;
		pgt = (PageTable*)ptr;
		pml4=NULL;
		pt_id = pd_id;
		pt_id = pdp_id;
		ptr = get_next_level_address<PageTable>((PageTable*)ptr,pg_dir_off);
		ptr = get_next_level_address<PageTable>((PageTable*)ptr,pg_off);
		ptr = get_next_level_address<void>( (PageTable*)ptr,pd_id);
		ptr = get_next_level_address<void>((PageTable*)ptr,pd_id);
		ptr = get_next_level_address<void>((PageTable*)ptr,pg_id);
		ptr = get_next_level_address<void>((PageTable*)ptr,pt_id);
		ptr = page_directory->get_next_level_address(pg_dir_off);
		remove_page_directory((*it).first,(*it).second );
		remove_page_table( pml4_entry , pdp_entry , pd_entry+i);
		remove_page_table((*it).first,(*it).second,(*it).third);
		remove_page_table(*it);
		req.cycle += (zinfo->mem_access_time*2);	//assume memory accessing cycle is 117 cycles
		req.cycle += (zinfo->mem_access_time*3);
		req.cycle += (zinfo->mem_access_time*3);
		req.cycle += (zinfo->mem_access_time*4);
		req.cycle += (zinfo->mem_access_time*4);
		req.cycle += (zinfo->mem_access_time*5);
		req.cycle += (zinfo->mem_access_time*6);
		return false;
		return false;
		return false;
		return false;
		return page;
		return page; //return page table
		return page_dir;
		return PAGE_FAULT_SIG;
		return PAGE_FAULT_SIG;
		return PAGE_FAULT_SIG;
		return PAGE_FAULT_SIG;
		return pg_table;
		return table;
		set_dirty = true;
		set_dirty = true;
		set_dirty = true;
		succeed = false;
		succeed = false;
		succeed = false;
		succeed = false;
		succeed = false;
		table = allocate_page_directory( pml4 , pdp, alloc_time);
		table = allocate_page_directory_pointer(pml4, alloc_time);
		table = allocate_page_table(pml4,pdp,pd, alloc_time);
		table = get_next_level_address<PageTable>(table,entry_id_list[i]); 
		table = get_tables(1,entry_id_vec);
		table = get_tables(2,entry_id_vec);
		table = get_tables(3, entry_id_vec);
		table = new PageTable(ENTRY_1024);
		table = new PageTable(ENTRY_512);
		unsigned page_dir = get_page_directory_off(addr , PAE_Normal);
		unsigned page_dir_ptr = get_page_directory_pointer_off( addr , PAE_Normal);
		unsigned page_table_num = (size+0x1fffff)>>21;
		unsigned pdpt_entry_id , unsigned pdt_entry_id , int& alloc_time)
		unsigned pg_id = get_pagetable_off(addr,mode);
		unsigned pg_off = get_pagetable_off(addr,mode);
		unsigned pt_entry_id = get_pagetable_off(addr , mode);
		unsigned pt_id = get_pagetable_off(addr , mode);
		unsigned pt_id = get_pagetable_off(addr,mode);
		validate_entry( page_directory_pointer , pdpt_entry ,page_dir);
		validate_entry( page_directory_pointer , pdpt_entry_id , table);
		validate_entry( table , pd_id , pg_ptr, pbuffer);
		validate_entry( table, pd_entry_id ,page);
		validate_entry( table,pd, pg_ptr, pbuffer);
		validate_entry(page_directory , pd_entry_id , table);		  
		validate_entry(page_directory,pd_entry_id, pg_ptr, is_buffer);
		validate_entry(pd_table , pdt_entry_id , pg_table);
		validate_entry(pdp_table,pdpt_entry_id , pd_table);
		validate_entry(pml4 , pml4_entry_id , table);
		validate_entry(pml4,pml4_entry_id,pdp_table);
		validate_entry(table , pt , pg_ptr, pbuffer);
		validate_entry(table , pt_entry_id , pg_ptr , is_buffer);
		validate_entry(table , pt_id ,pg_ptr, pbuffer);	
		validate_entry(table,pdp,pg_ptr, pbuffer);
		write_back = true;
		write_back = true;
		write_back = true;
		zinfo->page_shift = 12;
		zinfo->page_shift = 21;
		zinfo->page_size = 2*power(2,20);	//2MB
		zinfo->page_size = 4*power(2,10);	//4KB
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{
		{	
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}*/
		}*/
		}*/
		}*/
		}*/
		}*/
		}*/
	    pgt = (PageTable*)pdp_ptr;
	 }
	//4KB small pages
	//4MB Huge pages
	//address must align with 4M
	//allocate page directory first
	//first access memory get page directory address
	//first memory access,get page directory address
	//init page directory pointer , its entry num is 4
	//only on PAE-NORMAL mode,can allocate page table
	//page directory
	//page directory offset
	//page directory pointer offset
	//pdpt_entry of page_direcotry_pointer has already pointed to page directory 
	//point to page directory pointer table
	//point to page or page directory
	//point to page table pointer table 
	//second memory access,get page table address  
	//std::cout<<"map:"<<std::hex<<addr<<std::endl;
	//unsigned buffer_entry_id = get_buffer_table_off(addr,buffer_table_shift,mode);
	//unsigned buffer_entry_id = get_buffer_table_off(addr,buffer_table_shift,mode);
	//unsigned buffer_entry_id = get_buffer_table_off(addr,buffer_table_shift,mode);
	//update page table
	Address addr = req.lineAddr;
	Address addr = req.lineAddr;
	Address addr = req.lineAddr;
	Address result = get_block_id( req ,pgt,ptr,pg_id , mode, pbuffer , set_dirty, 
	alloc_time = 0;
	alloc_time = 0;
	allocate_time = 0;
	allocate_time = 0;
	allocate_time = 0;
	allocate_time = 0;
	assert( (pml4!=(unsigned)(-1)) && (pdp!=(unsigned)(-1)));
	assert( cur_pdt_num < 4 && pdpt_entry < 4 );
	assert( level >= 1 );
	assert( mode == LongMode_Normal);
	assert( mode == PAE_Normal && cur_pt_num< ENTRY_512);
	assert( mode == PAE_Normal);
	assert( mode== Legacy_Normal);
	assert( mode==Legacy_Normal );
	assert( page_num + pd_offset < 512);
	assert( pml4_entry_id<512 && cur_pdp_num<ENTRY_512);
	assert(mode!=LongMode_Huge && pml4_entry_id<512 && pdp_entry_id<512);
	assert(mode==Legacy_Normal);
	assert(mode==LongMode_Normal);
	assert(mode==LongMode_Normal);
	assert(mode==LongMode_Normal);
	assert(page_directory_pointer);
	assert(pdpt_num<ENTRY_4 && pd_num< ENTRY_512 && mode==PAE_Normal);
	assert(zinfo);
	BasePDTEntry* entry;
	BasePDTEntry* entry;
	BasePDTEntry* entry;
	bool pbuffer = false;
	bool pbuffer = false;
	bool pbuffer = false;
	bool set_dirty = false;
	bool set_dirty = false;
	bool set_dirty = false;
	bool succeed = false;
	bool succeed = false;
	bool succeed = false;
	bool succeed = true;
	bool succeed = true;
	bool succeed = true;
	bool succeed = true;
	bool succeed = true;
	bool succeed = true;
	bool succeed = true;
	bool succeed = true;
	bool succeed = true;
	bool succeed = true;
	bool succeed = true;
	bool succeed = true;
	bool succeed = true;
	bool succeed = true;
	bool succeed =true;
	bool succeed=true;
	bool write_back = false;
	bool write_back = false;
	bool write_back = false;  
	buffer_table_entry_num = zinfo->page_size/zinfo->block_size;
	buffer_table_shift = zinfo->page_shift-zinfo->block_shift;
	cur_page_table_num=0;
	delete page_directory_pointer;
	else
	else
	else
	else
	else
	else
	else
	else if( mode == Legacy_Huge )
	else if( mode == Legacy_Huge)
	else if( mode == LongMode_Huge )
	else if( mode == LongMode_Huge)
	else if( mode == LongMode_Middle )
	else if( mode == LongMode_Middle )
	else if( mode == LongMode_Normal)
	else if( mode == PAE_Huge)
	else if( mode==Legacy_Huge)
	else if(select==PAE_Huge)
	entry_id_vec[0]=pml4_id;
	entry_id_vec[1]=pdp_id;
	entry_id_vec[2]=pd_id;
	for( entry_list_ptr it=pd_entry.begin() ;it!=pd_entry.end(); it++)
	for( entry_list_ptr it=pd_entry.begin(); it!=pd_entry.end();it++ )
	for( entry_list_ptr it=pdpt_entry.begin() ; it!=pdpt_entry.end() ; it++)
	for( entry_list_ptr it=pdpt_entry.begin(); 
	for( entry_list_ptr it=pml4_entry.begin(); it!=pml4_entry.end();it++)
	for( entry_list_ptr it=pml4_entry.begin();it!=pml4_entry.end();it++)
	for( pair_list_ptr it= pdt_entry.begin();
	for( pair_list_ptr it=high_level_entry.begin(); it!=high_level_entry.end() ; it++)
	for( pair_list_ptr it=high_level_entry.begin(); it!=high_level_entry.end();it++)
	for( pair_list_ptr it=pdp_entry.begin(); it!=pdp_entry.end();it++)
	for( triple_list_ptr it = high_level_entry.begin(); it!=high_level_entry.end();it++)
	for( triple_list_ptr it=high_level_entry.begin() ; it!=high_level_entry.end() ; it++)
	for( unsigned i = 0; i<page_dir_num ; i++)
	for( unsigned i =0 ;i<page_table_num ; i++)
	for( unsigned i=0 ; i<page_num ; i++)
	for( unsigned i=0; i<dir_num;i++ )
	for( unsigned i=0; i<page_num ; i++)
	for( unsigned i=0; i<page_num;i++)
	for( unsigned i=0; i<page_table_num ;i++)
	for(unsigned i=0 ; i<ENTRY_4 ; i++)
	get_domains(addr , pml4 , pdp , pd , pt , mode);
	get_domains(addr , pml4_entry , pdp_entry ,pd_entry, pt_entry , mode);
	get_domains(addr , pml4_id , pdp_id , pd_id , pt_id , mode);
	get_domains(addr,pml4_id,pdp_id,pd_id,pt_id,mode);
	i++;
	if ( addr & 0x1fffff )
	if( !is_present(pml4, pml4_entry_id))
	if( !pdp_ptr)
	if( !ptr )
	if( !ptr )
	if( !table)
	if( (page_dir = get_next_level_address<PageTable>(page_directory_pointer, pdpt_entry))!=NULL )
	if( (pdp_table = get_next_level_address<PageTable>(pml4,pml4_entry_id)))
	if( (pdp_table= get_next_level_address<PageTable>(pml4, pml4_entry_id)) )
	if( addr & 0x1fffff)
	if( addr & 0x1fffff)
	if( addr & 0x3fffff )
	if( addr &0x7fffffff )
	if( addr&0x1fffff )
	if( addr&0x7fffffff )
	if( is_buffer )
	if( is_present(page_directory , pd_entry_id) )
	if( mode == Legacy_Normal )
	if( mode == Legacy_Normal )
	if( mode == LongMode_Huge)
	if( mode == LongMode_Middle)
	if( mode == LongMode_Normal)
	if( mode == LongMode_Normal)
	if( mode == PAE_Normal )
	if( mode == PAE_Normal)
	if( mode== Legacy_Normal )
	if( mode==PAE_Huge )
	if( pd_ptr )
	if( pdp_table )
	if( pdp_table )
	if( pml4)
	if( req.type == SETDIRTY)
	if( req.type == WRITEBACK)
	if( req.type == WRITEBACK)
	if( req.type==WRITEBACK)
	if( write_back )
	if(!ptr)
	if(addr & 0x3fffff)
	if(page_dir)
	if(page_dir)
	if(pdp_table)
	if(req.type == SETDIRTY)
	if(req.type==SETDIRTY)
	if(select == PAE_Normal)
	if(table == NULL)
	int alloc_time = 0;
	int allocate_time = 0;
	int allocate_time = 0;
	int allocate_time;
	int allocate_time;
	int allocate_time;
	int allocate_time;
	int latency = 0;
	int latency = 0;
	int latency = 0;
	int time = 0;
	int time;
	int time;
	int time;
	int time;
	int time;
	latency = zinfo->mem_access_time*(1+alloc_time);
	latency = zinfo->mem_access_time*(1+allocate_time);
	latency = zinfo->mem_access_time*(1+allocate_time);	//allocate overhead
	level--;	
	mapped_entry = NULL;
	mapped_entry = NULL;
	mapped_entry = NULL;
	page_directory_pointer = new PageTable(ENTRY_4);
	page_directory_pointer = NULL;
	PageTable *page_dir = get_next_level_address<PageTable>( page_directory_pointer , pdpt_num);
	PageTable* page=NULL;
	PageTable* page_dir = get_next_level_address<PageTable>(page_directory_pointer , pdp_entry_id);
	PageTable* page_dir = NULL;
	PageTable* pd_ptr = get_next_level_address<PageTable>( page_directory_pointer , pdp_id); 
	PageTable* pdp_ptr = get_next_level_address<PageTable>( pml4,pml4_id );
	PageTable* pdp_table = get_next_level_address<PageTable>( pml4 , pml4_entry_id);
	PageTable* pdp_table = NULL;
	PageTable* pdp_table = NULL;
	PageTable* pdp_table= get_next_level_address<PageTable>(pml4,pml4_entry_id);
	PageTable* pdp_table=get_next_level_address<PageTable>(pml4 , pml4_entry_id);
	PageTable* pg_dir_p = get_next_level_address<PageTable>( pml4,pml4_entry_id);
	PageTable* pgt = NULL;
	PageTable* pgt = NULL;
	PageTable* pgt = NULL;
	PageTable* table = get_next_level_address<PageTable>( page_directory_pointer , pdpt_entry_id);
	PageTable* table = get_next_level_address<PageTable>(page_directory,pd_entry_id);
	PageTable* table = NULL;
	PageTable* table;
	PageTable* table;
	PageTable* table;
	ptr = get_next_level_address<void>((PageTable*)ptr,pd_id);
	remove_root_directory();
	remove_root_directory();	//remove whole page table structures
	return false;
	return false;
	return get_block_id(req ,pgt,ptr, pt_id,mode,pbuffer ,
	return get_block_id(req, pgt, ptr , pg_id, mode,pbuffer , 
	return latency;
	return latency;
	return latency;
	return map_page_table(addr, pg_ptr, is_buffer, entry);
	return map_page_table(addr, pg_ptr, pbuffer, entry);
	return map_page_table(addr, pg_ptr, pbuffer, entry);
	return NULL;
	return NULL;
	return page;
	return page_dir;
	return pg_dir_p;
	return result;
	return succeed;
	return succeed;
	return succeed;
	return succeed;
	return succeed;
	return succeed;
	return succeed;
	return succeed;
	return succeed;
	return succeed;
	return succeed;
	return succeed;
	return succeed;
	return succeed;
	return succeed;
	return succeed;
	return succeed;
	return succeed;
	return succeed;
	return table;
	return table;
	return true;
	return true;
	return true;
	return true;
	return true;
	return true;
	return true;
	return true;
	std::vector<unsigned> entry_id_vec(4);
	table = get_next_level_address<PageTable>( pml4 , entry_id_list[i]);
	uint32_t access_counter = 0;
	uint32_t access_counter = 0;
	uint32_t access_counter = 0;
	unsigned base_addr = get_page_directory_pointer_off(addr , mode);
	unsigned base_entry_id = get_page_directory_off( addr, mode );
	unsigned base_pageNo = get_page_directory_off( addr , mode);
	unsigned dir_num = (size+0x7fffffff)>>30;
	unsigned i = 0;
	unsigned page_dir_num = (size+0x7fffffff)>>30;
	unsigned page_dir_ptr = get_page_directory_pointer_off(addr , PAE_Normal );
	unsigned page_num = (addr+0x3fffff)>>22;
	unsigned page_num = (size+0x1fffff) >>21;
	unsigned page_num = (size+0x3fffff)>>22;	//get page size
	unsigned page_table_num = (size+0x1fffff)>>21;
	unsigned page_table_num = (size+0x1fffff)>>21;
	unsigned pd_entry = get_page_directory_off(addr , mode);
	unsigned pd_entry_id = get_page_directory_off( addr , mode );
	unsigned pd_entry_id = get_page_directory_off(addr,mode);
	unsigned pd_id = get_page_directory_off(addr , mode);
	unsigned pd_id = get_page_directory_off(addr,mode);
	unsigned pd_id = get_page_directory_off(addr,mode);
	unsigned pd_offset =  get_page_directory_off( addr , PAE_Normal);
	unsigned pdp_entry = get_page_directory_pointer_off(addr , mode);
	unsigned pdp_id	= get_page_directory_pointer_off(addr , mode);
	unsigned pdp_id = get_page_directory_pointer_off( addr , mode);
	unsigned pdp_id = get_page_directory_pointer_off(addr , mode);
	unsigned pdp_offset = get_page_directory_pointer_off( addr , PAE_Normal);
	unsigned pg_dir_off = get_page_directory_off(addr,mode);
	unsigned pg_id;
	unsigned pg_id;
	unsigned pml4,pdp,pd,pt;
	unsigned pml4_entry , pdp_entry , pd_entry , pt_entry;
	unsigned pml4_entry = get_pml4_off(addr , mode);
	unsigned pml4_id,pdp_id,pd_id,pt_id;
	unsigned pml4_id,pdp_id,pd_id,pt_id;
	void* ptr = (void*)page_directory;
	void* ptr = get_next_level_address<void>(page_directory_pointer,pdp_id);
	void* ptr = get_next_level_address<void>(pdp_ptr,pdp_id );
	while( level>0 )
	zinfo->page_shift = 12;
	zinfo->page_shift = 30;
	zinfo->page_shift=21;
	zinfo->page_size = 2*power(2,20);
	zinfo->page_size = 4*power(2,10);
	zinfo->page_size=power(2,30);	
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	{
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
  assert(zinfo);
  buffer_table_entry_num = zinfo->page_size/zinfo->block_size;
  buffer_table_shift = zinfo->page_shift - zinfo->block_shift;
  else if(select == LongMode_Huge )			//1GB
  else if(select == LongMode_Middle )			//2MB
  futex_init(&table_lock);
  if(select == LongMode_Normal)			//4KB
  PageTable* table = gm_memalign<PageTable>(CACHE_LINE_BYTES,1);
  pml4=new (table) PageTable(512);
  {
  {
  {
  }
  }
  }
 * 2015-xxx by YuJie Chen
 * email:    YuJieChen_hust@163.com
 * function: extend zsim-nvmain with some other simulation,such as tlb,page table,page table,etc.  
 * memory access cycles: 117 cycles
 *%attention: information of current page tables must can be contained within page directory entries before or when allocating page table
 *%attention: number of page directory must no more than 4
 */
 */
 */
 */
 */
 */
 */
 */
 */
 */
 */
 */
 */
 *@function:
 *@function:
 *@function:
 *@function: access page table
 *@function: allocate page directory table according to input
 *@function: allocate page table according to input
 *@function: allocate page tables
 *@function: delete page table referred by (pdpt_num[entry id of page directory pointer],pd_num[entry id of page directory])
 *@function: delete several pages referred by element of pd_entry
 *@function: remove page directory, although this is seldom used , but it's provided for complete function
 *@function: remove page table whose address is recorded in page directory's page_table_idth entry
 *@function: remove several number of page tables
 *@param addr:
 *@param addr:
 *@param page_table_id: entry num of page directory,page table this entry pointed to can be removed if the whole page table is unuseful
 *@param pd_entry: entry id of page directory 
 *@param pd_entry: list which record entry num of page direcotry , these entries point to page table will be removed 
 *@param pd_num: entry id of page directory table
 *@param pdp_entry: list of (page_directory_pointer entry id , page_directory entry id)
 *@param pdpt_entry:
 *@param pdpt_entry: list of page directory pointer entry id
 *@param pdpt_num: entry id of page directory pointer table
 *@param pdt_entry: list of (page directory pointer entry id , page direcotry entry id)
 *@param size:
 *@param size:
 *@req: memory request issued from TLB 
 *@return: remove succeed , return true; failed return false
 {
 }
#include "common/common_functions.h"
#include "core.h"
#include "DRAM-buffer/DRAM_buffer_block.h"
#include "galloc.h"
#include "memory_hierarchy.h"
#include "pad.h"
#include "page-table/page_table.h"
#include "timing_core.h"
#include "zsim.h"
#include <iterator>
#include <list>
#include <vector>
/*
/*
/*
/*
/*
/*
/*
/*
/*
/*
/*
/*
/*
/*****-----functional interface of Legacy-Paging----*****/
/*****-----functional interface of LongMode-Paging----*****/
/*****-----functional interface of paging----*****/
/****----basic call back of Legacy-Paging----****/
/*--------------PAE Paging------------*/
/*-------------legacy paging------------*/
/*-----------LongMode Paging--------------*/
//allocate
//constructor of PAE paging
//delete whole structures of page tables
//PageTable* LongModePaging::pml4;
//remove
Address LongModePaging::access(MemReq &req)
Address NormalPaging::access(MemReq &req )
Address PAEPaging::access(MemReq &req)
bool LongModePaging::allocate_page_directory(pair_list high_level_entry)
bool LongModePaging::allocate_page_directory_pointer(entry_list pml4_entry)
bool LongModePaging::allocate_page_table(Address addr , Address size)
bool LongModePaging::allocate_page_table(triple_list high_level_entry)
bool LongModePaging::remove_page_directory(pair_list high_level_entry)
bool LongModePaging::remove_page_directory(unsigned pml4_entry_id , unsigned pdp_entry_id)
bool LongModePaging::remove_page_directory_pointer(entry_list pml4_entry )
bool LongModePaging::remove_page_directory_pointer(unsigned pml4_entry_id)
bool LongModePaging::remove_page_table( triple_list high_level_entry)
bool LongModePaging::remove_page_table(Address addr , Address size)
bool LongModePaging::remove_page_table(unsigned pml4_entry_id , unsigned pdp_entry_id , unsigned pd_entry_id)
bool LongModePaging::unmap_page_table( Address addr)
bool NormalPaging::allocate_page_table(Address addr , Address size)
bool NormalPaging::allocate_page_table(entry_list pd_entry)
bool NormalPaging::remove_page_table( Address addr , Address size)
bool NormalPaging::remove_page_table(entry_list pd_entry)
bool NormalPaging::remove_page_table(unsigned pd_entry_id)
bool NormalPaging::unmap_page_table( Address addr)
bool PAEPaging::allocate_page_table(Address addr , Address size)
bool PAEPaging::allocate_page_table(pair_list pdt_entry)
bool PAEPaging::allocate_pdt(Address addr , Address size)
bool PAEPaging::allocate_pdt(entry_list pdpt_entry)
bool PAEPaging::remove_page_table( Address addr, Address size)
bool PAEPaging::remove_page_table( unsigned pdpt_num , unsigned pd_num )
bool PAEPaging::remove_page_table(pair_list pdp_entry)
bool PAEPaging::remove_pdt( Address addr , Address size)
bool PAEPaging::remove_pdt( entry_list pdpt_entry)
bool PAEPaging::remove_pdt( unsigned pdp_entry_id)
bool PAEPaging::unmap_page_table( Address addr)
inline PageTable* LongModePaging::get_tables(unsigned level , std::vector<unsigned> entry_id_list)
int LongModePaging::map_page_table( Address addr, void* pg_ptr , bool pbuffer, BasePDTEntry*& mapped_entry)
int LongModePaging::map_page_table(Address addr, void* pg_ptr, bool pbuffer)
int NormalPaging::map_page_table( Address addr, void* pg_ptr, bool is_buffer )
int NormalPaging::map_page_table(Address addr ,void* pg_ptr , bool is_buffer, 
int PAEPaging::map_page_table(Address addr, void* pg_ptr , bool pbuffer, BasePDTEntry*& mapped_entry)
int PAEPaging::map_page_table(Address addr, void* pg_ptr, bool pbuffer)
lock_t LongModePaging::table_lock;
lock_t NormalPaging::table_lock;
LongModePaging::LongModePaging(PagingStyle select): mode(select),cur_pdp_num(0),cur_pd_num(0),cur_pt_num(0)
LongModePaging::~LongModePaging()
NormalPaging::NormalPaging(PagingStyle select): mode(select),cur_page_table_num(0)
NormalPaging::~NormalPaging()
PAEPaging::PAEPaging(PagingStyle select): mode(select) , cur_pdt_num(0),cur_pt_num(0)
PAEPaging::~PAEPaging()
PageTable* LongModePaging::allocate_page_directory( unsigned pml4_entry_id , unsigned pdpt_entry_id, int& allocate_time )
PageTable* LongModePaging::allocate_page_directory_pointer( unsigned pml4_entry_id, int& allocate_time)
PageTable* LongModePaging::allocate_page_table(unsigned pml4_entry_id , 
PageTable* NormalPaging::allocate_one_pagetable(unsigned pd_entry_id, int& allocate_time)
PageTable* PAEPaging::allocate_page_table( unsigned pdpt_entry_id , unsigned pd_entry_id , int &allocate_time)
PageTable* PAEPaging::allocate_pdt( unsigned pdpt_entry , int & alloc_time)
void LongModePaging::remove_root_directory()
void NormalPaging::remove_root_directory()
void PAEPaging::remove_root_directory()
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{ 
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}