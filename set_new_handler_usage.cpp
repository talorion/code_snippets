//function to call if operator new can't  allocate anough memory
void outOfMem()
{																	//By the way , consider what happens if
	std::err <<"Unable to satisfy request for memory"<<std::endl; 	//memory must be dynamically allocated during the 
	std::abort();													//course of writing the error message to std::err
}

int main()
{
	std::set_new_handler(outOfMem);
	int *pBigDataArray = new int[100000000L];
	//...
}