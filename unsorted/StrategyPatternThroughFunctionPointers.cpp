class GameCharacter;			// forward decleration

//function for the default health calculation algorithm
int defaultHealthCalc(const GameCharacter& gc);

class GameCharacter
{
public:
	typedef int (*HelathCalcFunc)(const GameCharacter&);

	explicit GameCharacter(HelathCalcFunc hcf = defaultHealthCalc)
		:healthfunc(hcf)
	{ /* … */}

	int healthValue() const{return healthfunc(*this);}
	//…
private:
	HelathCalcFunc healthfunc;
};

class EvilBadGuy: public GameCharacter
{
public:
	explicit EvilBadGuy(HelathCalcFunc hcf = defaultHealthCalc)
		:GameCharacter(hcf)
	{ /* … */}
};

int looseHealthQuickly(const GameCharacter&);	//health calculation
int looseHealthSlowly(const GameCharacter&);	//funcs with different behaivoir


EvilBadGuy ebg1(looseHealthQuickly);		// same type characters with diffrenet
EvilBadGuy ebg1(looseHealthSlowly);		// health related behavior
