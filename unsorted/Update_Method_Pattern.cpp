class Entity{
public:
	Entity():
		x_(0),
		y_(0)
	{}
	
	virtual ~Entity(){};
	virtual void update() =0;
	
	double x() const(){return  x_;}
	double y() const(){return  y_;}
	
	void setX(double x){ x_ = x;}
	void setY(double y){ y_ = y;}
	
private:
	double x_;
	double y_;
};

class Skeleton:public Entity{
public: 
	Skeleton():
		patrollingLeft_(false)
	{}
	
	virtual void update(){
		if (patrollingLeft_){
			setX(x() - 1);
			if(x() == 0) patrollingLeft_ = false;
		}else{
			setX(x() + 1);
			if(x() == 100) patrollingLeft_ = true;
		}
	}

private:
	bool patrollingLeft_;
};

class World{
public:
	World():
		numEntities_(0)
	{}
	
	void gameLoop(){
		while(true){
			//Handle user input ...
			
			//Update each entity
			for(int i = 0; i<numEntities_; ++i){entities_[i]->update();}
			
			//Physics and rendering...
		}
	}
	
private:
	Entity* entities_[MAX_ENTITIES];
	int numEntities_;
};
