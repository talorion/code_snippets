class Airport { /* … */};

class Airplane 
{
public:
	virtual void fly(const Airport& destination) = 0;
};

void Airplane::fly (const Airport& destination)		// an implementatin of 
{							// a pure virtual function offering									//default code for flying an airplane
}							// to the given deatination						

class ModelA: public Airplane 
{
public:
	virtual void fly(const Airport& destination)
	{Airplane ::fly(destination)}
};

class ModelB: public Airplane 
{
public:
	virtual void fly(const Airport& destination)
	{Airplane ::fly(destination)}
};


class ModelC: public Airplane 
{
public:
	virtual void fly(const Airport& destination);
};

void ModelC::fly (const Airport& destination)
{
	// code flying a ModelC airplane to destination
}
