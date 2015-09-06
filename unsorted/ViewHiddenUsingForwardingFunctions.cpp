class Base
{
public:
	virtual void mf1() =0;
	virtual void mf1(int);
	//...
};

class Derived :private Base
{
public:

	virtual void mf1(){Base::mf1();}
	//...
};
