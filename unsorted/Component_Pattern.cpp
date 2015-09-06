class Component{
public:
	virtual ~Component();
	virtual void receive(int message) =0;
};

class InputComponent: public Component{
public:
	virtual ~InputComponent();
	virtual void update(GameObject& obj) = 0;
};

class PlayerInputComponent : public InputComponent{
public:
	virtual void update(GameObject& obj){
		switch(Controller::getJoystickDirection())
		{
		case DIR_LEFT:{obj.velocity -= WALK_ACCELERATION; break;}
		case DIR_RIGHT:{obj.velocity += WALK_ACCELERATION; break;}
		}
	}
	
private:
	static const int WALK_ACCELERATION = 1;
	
};

class DemoInputComponent : public InputComponent{
public:
	virtual void update(GameObject& obj){
		//AI to automatically control Bjorn
	}
};

class PhysicsComponent: public Component{
public:
	virtual ~PhysicsComponent();
	virtual void update(GameObject& obj, World& world) =0;
};

class BjornPhysicsComponent: public: PhysicsComponent{
public:
	virtual void update(GameObject& obj, World& world){
		obj.x += obj.velocity;
		world.resolveCollision(volume_, obj.x, obj.y, obj.velocity);
	}
	
private:
	Volume volume_;
};

class GraphicsComponent: public Component{
public:
	virtual ~GraphicsComponent();
	virtual void update(GameObject& obj, Graphics& graphics) =0;
};

class BjornGraphicsComponent:public GraphicsComponent{
public:
	virtual void update(GameObject& obj, Graphics& graphics){
		Sprite* sprite = &spriteStand_;
		if(obj.velocity < 0){
			sprite = &spriteWalkLeft_;
		}else if(obj.velocity > 0){
			sprite = &spriteWalkRight_;
		}
		
		graphics.draw(*sprite, obj.x, obj.y);
	}

private:
	Sprite spriteStand_;
	Sprite spriteWalkLeft_;
	Sprite spriteWalkRight_;
};

class ContainerObject{
public:
	void send(int message){
		for(int i=0; i< MAX_COMPONENTS; ++i){
			if(components_[i] != NULL){
				components_[i]->receive(message);
			}
		}
	}
private:
	static const int MAX_COMPONENTS = 10;
	Component* components_[MAX_COMPONENTS];
};

class GameObject{
public:
	int velocity;
	int x;
	int y;

public:
	GameObject(	InputComponent* input, 
				PhysicsComponent* physics,
				GraphicsComponent* graphics ):
		input_(input),
		physics_(physics),
		graphics_(graphics)
	{}

	void update(World& world, Graphics& graphics){
		//Apply user input to hero's velocity.
		input_->update(*this);
		//Modify position by velocity
		physics_.update(*this, world);
		//Draw the appropriate sprite;
		graphics_.update(*this, graphics);
	}
	
private:
	InputComponent*		input_;
	PhysicsComponent*	physics_;
	GraphicsComponent*	graphics_;
};

int main(){
	
	Bjorn* bjorn = new Bjorn(new PlayerInputComponent());

	return 0;
}