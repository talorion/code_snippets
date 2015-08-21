class WidgetImpl 	//class for widget data
{ 			//details are unimportant
private:
	int a, b, c;		//possibly lots if data –
	std::vector<double> v;	// expensive to copy
};

class Widget			//class using the pimpl idiom
{
public:
	Widget(const Widget& rhs);
	Widget& operator=(const Widget& rhs)		// to copy a Widget, copy its
	{					// WidgetImpl object. For
		//...					// details on implementing 
		*pImpl= *(rhs.pImpl);			// operator= in general,
		//...					// see items 10, 11, and 12
	}
	//...
private:
	WidgetImpl *pImpl;				// ptr to ibject with this
};						//Widget’s data

namespace std
{
	template<>				//this is a specialized version 
	void swap<Widget>(Widget& a, Widget& b)	// of std::swap for when T is 
	{					//Widget
		swap(a.pImpl, b.pImple);		//to swap Widgets, swap their
	}					//pImpl pointers; this won't compile.
}

template<typename T>
void doSomething(T& obj1, T& obj2)
{
	using std::swap;		// make std::swap aviable in this function 
	swap(obj1, obj2);		// call the best swap for objects of type T
}