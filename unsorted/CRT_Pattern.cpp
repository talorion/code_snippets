template<typename T>		// "mixin-style" base class for
class NewHandlerSupport{	// class-specific set_new_handler
public:							// support
	static std::new_handler set_new_handler(std::new_handler p) throw;
	static void* operator new(std::size_t size) throw (std::bad_alloc);
	//...					//other versions of op. new see Item 52
	
private:
	static std::new_handler currentHandler;
};

template<typename T>
std::new_handler NewHandleSupport<T>::set_new_handler(std::new_handler p) throw
{
	std::new_handler oldHandler = currentHandler;
	currentHandler = p;
	return oldHandler;
}

template<typename T>
void* NewHandleSupport<T>::operator new(std::size_t size) throw (std::bad_alloc)
{
	NewHandlerHolder h(std::set_new_handler(currentHandler));
	return ::operator new(size);
}

//this initializes each currentHandler to null
template<typename T>
std::new_handler NewHandlerSupport<T>::currentHandler = 0;

// With this template, adding set_new_handler support to Widget is easy: Widget just inherits
//from NewHandlerSupport<Widget>.
class Widget: public NewHandlerSupport<Widget>
{
	//...	
} ;
