int  v = 4; // a normal int that can be modified
const int w = 2; // const int can be initialized, not modified thereafter
const int* pX; // changeable pointer to constant int
int* const pY; // constant pointer to changeable int
const int* const pZ; // const pointer to const int
const int& u; // behaves like const int except at copiing

class Constness
{
private:
	int var3; // member variable
	const int var2; // constant member variable, must be initialized in the initialization List 
	mutable int m_var3;// mutable member variable can be modified even by const member functions.

public:
	int a();	 // function retuns a normal int
	const int b(); // function retuns a const int
	const int* c(); // function retuns a changeable pointer to constant int
	int* const d(); // function retuns a constant pointer to changeable int
	const int* const e(); // function retuns a const pointer to const int

	// constant functions are the only callable functions from const objects and object references
	int f() const; // constant function retuns a normal int
	const int g() const; // constant function retuns a const int
	const int* h() const; // constant function retuns a changeable pointer to constant int
	int* const i() const; // constant function retuns a constant pointer to changeable int
	const int* const j() const; // constant function retuns a const pointer to const int

};