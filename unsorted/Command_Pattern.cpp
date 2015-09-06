class Command
{
public:
	virtual ~Command(){}
	virtual void execute(GameActor& actor) =0;

};

class JumpCommand : public Command
{
public:
	virtual void execute(GameActor& actor)
	{
		actor.jump();
	}
};

class FireCommand : public Command
{
public:
	virtual void execute(GameActor& actor)
	{
		actor.fire();
	}
};

class InputHandler
{
public:
	Command* handleInput()
	{
		if(isPressed(BUTTON_X)) return buttonX_;
		if(isPressed(BUTTON_Y)) return buttonY_;
		
		return NULL;
	}
	
private:
	Command* buttonX_;
	Command* buttonY_;
}

int main(){
	Command* command = InputSystem.handleInput();
	if(command)
	{
		command->execute(actor);
	}
}