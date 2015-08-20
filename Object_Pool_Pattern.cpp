class Particle{
friend class ParticlePool;

private:
	Particle():
		framesLeft_(0)
	{}
	
public:
	void init(double x, double y, double xVel, double yVel, int lifetime){
		x_ = x;
		y_ = y;
		xVel_ = xVel;
		yVel_ = yVel;
		framesLeft_ = lifetime;
	}
	
	bool animate(){
		if(!inUse()) return false;
		
		framesLeft_--;
		x_ += xVel_;
		y_ += yVel_;
		
		return framesLeft_ == 0;
	}
	
	bool inUse() const{return framesLeft_ > 0;}
	
	Particle* getNext() const {return state_.next();}
	void setNext(Particle* next){state_.next = next;}
	
private:
	int framesLeft_;
	
	union{
		struct{				//state when it's in use
			double x_;
			double y_;
			double xVel_;
			double yVel_;
		}live;
		Particle* next; 	//state when it's aviable
	}state_;
};

class ParticlePool{
public:
	ParticlePool(){
		firstAviable_ = &particles_[0];					//the first one is aviable.
		for(int i = 0; i < POOL_SIZE -1; ++i){			//Each particle points to the next
			particles_[i].setNext(&particles_[i+1]);
		}
		particles_[POOL_SIZE - 1].setNext(NULL);		//The last one terminates the list
	}

	void create(double x, double y, double xVel, double yVel, int lifetime){
		assert(firstAviable_ != NULL)	//Make sure the pool isn't full
		Particle newParticle = firstAviable_;//Remove it from the aviable list
		firstAviable_ = newParticle->getNext();
		
		newParticle->init(x,y, xVel, yVel, lifetime);
	}
	
	void animate(){
		for(int i=0; i<POOL_SIZE; ++i){
			if(particles_[i].animate()){
				particles_[i].setNext(firstAviable_); //Add this particle to the front of the list
				firstAviable_ = &particles_[i];
			}
		}
	}
	

	
private:
	static const int POOL_SIZE =100;
	Particle particles_[POOL_SIZE];
	Particle* firstAviable_;
};