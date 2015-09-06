class GameCharacter; // forward decleration

//function for the default health calculation algorithm
int defaultHealthCalc(const GameCharacter& gc); 

class GameCharacter
{
public:
	//HealthCalcFunc is any callable entity that can be called with 
	//anything compatible with a GameCharacter and that returns anything 
	//compatible with an int; see below for details
	typedef std::tr1::function<int (const GameCharacter&)> HelathCalcFunc ;

	explicit GameCharacter(HelathCalcFunc hcf = defaultHealthCalc)
		:healthfunc(hcf)
	{ /* … */}

	int healthValue() const {return healthfunc(*this);}

	//…
private:
	HelathCalcFunc healthfunc;
};

short calcHealth(const GameCharacter&); 	//health calculation function; note non-int type

struct HealthCalculator			//class for health calculation function objects
{
	int operator()(const GameCharacter&) const { /* … */}};

class GameLevel									 
{								
public:
	float health(const GameCharacter&) const; //health calculation mem function; note none-int
	//…				//return type
};

class EvilBadGuy
	:public GameCharacter
{
public:
	explicit EvilBadGuy(HelathCalcFunc hcf = defaultHealthCalc)
		:GameCharacter(hcf)
	{ /* … */}	
//
};

class EyeCandyCharecter
	:public GameCharacter		// another character type; assume
{															// same constructor as EvilBadGuy
};
		
EvilBadGuy ebg1(calcHealth);		//charater using a helath calculation function

EyeCandyCharecter ecc1(HealthCalculator()); 	//character using a health calculating object

GameLevel currentLevel;

EvilBadGuy  ebg2(std::tr1::bind(&GameLevel::health, currentLevel, _1));
