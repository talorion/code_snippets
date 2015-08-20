class HeroineState{
public: 
	virtual ~HeroineState(){}
	virtual void enter(Heroine& heroine);
	virtual void exit(Heroine& heroine);
	virtual HeroineState* handleInput (Heroine& heroine, Input input){}
	virtual void update(Heroine& heroine){}
	
	
};

class DuckingState:public HeroineState{
public:
	DuckingState():chageTime_(0){}
	
	virtual void enter(Heroine& heroine){heroine.setGraphics(IMAGE_DUCK);}
	
	virtual HeroineState* handleInput (Heroine& heroine, Input input){
		if(input == RELESE_DOWN){
			return new StandingState;
		}
		//Stay in this State
		return NULL;
	}
	
	virtual void update(Heroine& heroine){
		chageTime_++;
		if(chageTime_ > MAX_Charge){
			heroine.superBomb();
		}
	}
	
private:
	int chageTime_;
};

class StandingState:public HeroineState{
public: 
	virtual ~HeroineState(){}
	
	virtual HeroineState* handleInput (Heroine& heroine, Input input){
		if(input == PRESS_DOWN){
			//other code
			return new DuckingState();
		}
		//Stay in this State
		return NULL;
	}
};

class Heroine{
public:
	virtual void handleInput(Input input){
		HeroineState* state = state_->handleInput(*this, input);
		if(state != NULL){
			state_->exit(*this);
		
			delete state_;
			state_ = state;
			
			state_->enter(*this);
		}
	}
	
	virtual void update(){
		state_->update(*this);
	}
	
	void superBomb(){/* ... */}
	
private:
	HeroineState* state_;

};