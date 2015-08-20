class Monster{
public:
	virtual ~Monster(){}
	virtual Monster* clone() = 0;
};

class Ghost: public Monster{
public:
	Ghost(int health, int speed)
		:health_(health),
		speed_(speed)
		{}
		
	virtual Monster* clone(){return new Ghost( health_, speed_);}
	
private:
	int health_;
	int speed_;
};

class Spawner{
public:
	virtual ~Spawner(){}
	virtual Monster* spawnMonster() =0;
};

template <class T>
class SpawnerFor:public Spawner{
public:
	virtual Monster* spawnMonster(){return new T();}
};

int main(){
	//Monster* ghostPrototype = new Ghost(15, 3);
	//Spawner* ghostSpawner = new Spawner(ghostPrototype);

	Spawner* ghostSpawner = new SpawnerFor<Ghost>();
	return 0;
}