class Base
{
public:
	virtual void mf1() =0;
	virtual void mf1(int);

	virtual void mf2();

	void mf3();
	void mf3(double);
	//...
};

class Derived :private Base
{
private:
	int x;
public:
	using Base::mf1;
	using Base::mf3;

	virtual void mf1();
	void mf3();
	void mf4();
	//...
};