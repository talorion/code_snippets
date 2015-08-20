class Audio{
public:
	virtual ~Audio(){}
	virtual void playSound(int soundID) =0;
	virtual void stopSound(int soundID) =0;
	virtual void stopAllSounds() =0;
};

class NullAudio: public Audio{ //Null Object Pattern
public:
	virtual void playSound(int soundID) { /* Do nothing */}
	virtual void stopSound(int soundID) { /* Do nothing */}
	virtual void stopAllSounds() 		{ /* Do nothing */}
};

class ConsoleAudio:public Audio{
public:
	virtual void playSound(int soundID){
		//play sound using console audio api ...
	}
	
	virtual void stopSound(int soundID){
		//Stop sound using console audio api ...
	}
	
	virtual void stopAllSounds(){
		//Stop all sounds using console audio api ...
	}
};

class LoggedAudio: public Audio{
public:
	LoggedAudio(Audio &wrapped):
		wrapped_(wrapped)
	{}
	
	virtual void playSound(int soundID){
		log("play sound");
		wrapped_.playSound(soundId);
	}
	
	virtual void stopSound(int soundID){
		log("stop sound");
		wrapped_.stopSound(soundId);
	}
	
	virtual void stopAllSounds(){
		log("stop all sound");
		wrapped_.stopAllSounds(soundId);
	}
	
private:
	void log(const char* message){/* code to log message */}
	
private:
	Audio &wrapped_;
};

class Locator{
public:
	static void initialize(){ service_ = &nullService;}

	static Audio& getAudio(){
		assert(service_ != NULL);
		return *service_;
	}
	
	static void provide(Audio* service){
		if(service == NULL){ 
			service_ = &nullService;
		}else{
			service_ = service;
		}
	}
	
private:
	static Audio* service_;
	static NullAudio* nullService;
};

void enableAudioLogging(){
	
	Audio *service = new LoggedAudio(Locator::getAudio());	//decorate the existing service.
	Locator::provide(service);								//swap it in
}

int main(){

	Locator::initialize();
	ConsoleAudio* audio = new ConsoleAudio();
	Locator::provide(audio);
	
	// somwhere else
	Audio* audio = Locator::getAudio();
	audio->playSound(VERY_LOUD_BANG);
	
	return 0;
}