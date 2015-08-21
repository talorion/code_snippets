class Uncopyable
{
protected:		// allow 
	Uncopyable() {}; 	// construction
	~Uncopyable() {}; // and destruction of derived objects
private:
	Uncopyable(const Uncopyable&); // … but prevent copying
	Uncopyable& operator= (const Uncopyable&); 
}

class ImplUncopyable : private Uncopyable //prohibit copying 
{
public: 
	explicit ImplUncopyable();
	~ImplUncopyable();
};