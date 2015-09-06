void setHealth(int wizard, int amount);
void setWisdom(int wizard, int amount);
void setAgility(int wizard, int amount);

void playSound(int soundId);
void spawnParticles(int particleType);

enum Insruction{
	INST_SET_HEALTH =		0x00,
	INST_SET_WISDOM = 		0x01,
	INST_SET_AGILITY = 		0x02,
	INST_PLAY_SOUND = 		0x03,
	INST_SPAWN_PARTICLES =	0x04,
	INST_LITERAL = 			0x05,
	INST_GET_HEALTH = 		0x06,
	INST_GET_WISDOM = 		0x07,
	INST_GET_AGILITY = 		0x08,
	INST_ADD =				0x09,
};

class VM{
public:
	VM():
		stackSize_(0)
	{}

	void interpret(char bytecode[], int size){
		for(int i= 0; i < size; ++i){
			char instruction = bytecode[i];
			switch(instruction){
				case INST_SET_HEALTH:{ 
					int amount = pop();
					int wizard = pop();
					setHealth(wizard, amount); 
					break;
				}
				case INST_SET_WISDOM:{ 
					int amount = pop();
					int wizard = pop();
					setWisdom(wizard, amount); 
					break;
				}
				case INST_SET_AGILITY:{ 
					int amount = pop();
					int wizard = pop();
					setAgility(wizard, amount); 
					break;
				}
				case INST_PLAY_SOUND:{ 
					playSound(pop()); 
					break;
				}
				case INST_SPAWN_PARTICLES:{ 
					spawnParticles(pop()); 
					break;
				}
				case INST_LITERAL{
					int value = bytecode[++i];
					push(value);
					break;
				}
				case INST_GET_HEALTH{
					int wizard = pop();
					push(getHealth(wizard));
					break;
				}
				// ...
				case INST_ADD{
					int b = pop();
					int a = pop();
					push(a+b);
					break;
				}
				default{break;}
			}
		}
	}
	
private:
	void push(int value){
		assert(stackSize_ < MAX_STACK);
		stack_[stackSize_++] = value;
	}
	
	int pop(){
		assert(stackSize_ > 0);
		return stack_[--stackSize_];
	}
	
private:
	static const int MAX_STACK=128;
	int stackSize_;
	int stack_[MAX_STACK];
};