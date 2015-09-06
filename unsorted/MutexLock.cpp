class Lock
{
public: 
	explicit Lock(std::Mutex *pm) 		//init shared_ptr with Mutex
		:mutexPtr(pm, unlock)		//to point to and the unlock func
	{								//as the deleter
		lock(mutexPtr.get());		//see Item15 for info on „get()“
	}
private:
	std::tr1::shared_ptr<std::Mutex> mutexPtr;//use shared_ptr  instead of raw pointer
};