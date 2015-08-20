class Actor{
public:
	Actor() : currentSlapped_(false){}
	
	virtual ~Actor(){}
	virtual void update() = 0;
	
	void swap(){
		currentSlapped_ = nextSlapped_		//swap the Buffer
		nextSlapped_ =false; //Clear the new "next" buffer.
	}
	
	void slap()			{nextSlapped_ = true;}
	bool wasSlapped()	{return currentSlapped_:}
	
private:
	bool currentSlapped_;
	bool nextSlapped_;
};

class Comedian:public Actor{
public:
	void face(Actor* actor){facing_ = actor;}
	
	virtual void update(){
		if(wasSlapped()) facing_->slap();
	}
	
private:
	Actor* facing_;
};

class Stage{
public:
	void add(Actor* actor, int index){
		actors_[index] = actor;
	}
	
	void update(){
		for (int i =0; i<NUM_ACTORS; ++i){
			actors_[i]->update();
		}
		for (int i =0; i<NUM_ACTORS; ++i){
			actors_[i]->swap();
		}
	}
	
private:
	static const int NUM_ACTORS = 3;
	Actor* actors_[NUM_ACTORS];
	
};

int main(){

	return 0;
}