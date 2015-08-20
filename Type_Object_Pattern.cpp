class Breed{
public:
	Breed(Breed* parent,int health, const char* attack):
		health_(health),
		attack_(attack)
	{
		if(parent != NULL){
			if(health == 0) health_ = parent->getHealth();
			if(attack == NULL) attack_ = parent->getAttack();
		}
	}
	
	Monster* newMonster(){ return newMonster(*this);} //factory method pattern
	
	int getHealth() const { return health_;}
	
	const char* getAttack()const {return attack_;}
	
private:
	int health_;
	const char* attack_;
};

class Monster{
	friend class Breed;

public;
	~Monster(){}
	virtual const char* getAttack() const {return breed.getAttack();}
	
private:
	Monster(Breed& breed):
		health_(breed.getHealth()),
		breed_(breed)
	{}
	
private:
	int health_;
	Breed& breed_;
};

int main(){

	Breed Troll(NULL, 25, "The troll hits you");
	Breed Troll_Archer(&Troll, 0, "The troll archer fires anarrow");
	Breed Troll_Wizard(&Troll, 0, "The toll wizard casts a spell on you!");
	
	Breed dragon(NULL, 230, "The dragon breathes fire!");

	Monster* monster = dragon.newMonster();
	return 0;
}
