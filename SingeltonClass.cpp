class SingeltonClass
{
private:
	static SingeltonClass* instance;					//singelton

private:
	SingeltonClass(void);									// not initialazeable
	SingeltonClass(const SingeltonClass&);					// not copyable
	SingeltonClass& operator=(const SingeltonClass&);		// not assignable
	~SingeltonClass(void);									// not desctructable

public:
	static SingeltonClass& getInstance();
	static void destroy();

};  // end class SingeltonClass



SingeltonClass* SingeltonClass::instance = NULL;

SingeltonClass::SingeltonClass()
{
}	// end constructor

SingeltonClass::SingeltonClass(const SingeltonClass&) 
{
}	// end copy constructor

SingeltonClass::SingeltonClass& operator=(const SingeltonClass&)
{
}	// end assigment operator

SingeltonClass::~SingeltonClass(void)
{
}	// end dtor

SingeltonClass& SingeltonClass::getInstance()
{
	if ( !instance ){
		instance = new SingeltonClass();
	}
	return *instance;
} // end getInstance

void SingeltonClass::destroy()
{
	if ( instance )
		delete instance;
	instance = 0;
} // end destroy