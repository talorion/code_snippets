void * operator new(std::size_t size) trow(std::bad alloc)
{									// your operator new might 
	using namespace std;			// take additional params
	
	if (size == 0){					// handle 0-byterequests
		size = 1;					// by treating them as 
	}								// 1-byte requests
	
	while(true)
	{
		//attempt to allocate size bytes
		
		if(/*the alloction was successful*/)
			return /*(a pointer to the memory)*/
			
		// allocation was unsuccessful; find out what the 
		// current new-handling function is
		new_handler globalHandler = set_new_handler(0);
		set_new_handler(globalHandler);
		if(globalHandler) (*globalHandler)();
		else throw std::bad_alloc();
	}
}

void operator delete(void *rawMemory) throw()
{
	if(rawMemory == 0) return;			//do nothing of the null pointer
										// is being deleted
	//deallocate the memory pointed to by rawMemmory
}