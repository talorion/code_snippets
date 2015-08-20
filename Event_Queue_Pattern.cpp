struct PlayMessage{
	SoundId id;
	int volume;
};

class Audio{
public:
	static void init(){
		head_ = 0;
		tail_ = 0;
	}

	static void playSound(SoundId id, int volume){
	
		for(int i=head; i != tail; i = (i+1)%MAX_PENDING){ //check for multible requests
			if(pending_[i].id == id){
				pending_[i].volume = max(volume, pending[i].volume); //take the louder one
				return; //don't need to enqueue
			}
		}
		
		assert((tail_ + 1) % MAX_PENDING != head_);
		
		pending_[tail_].id = id;
		pending_[tail_].volume = volume;
		
		tail_ = (tail_ +1) % MAX_PENDING;
	}
	
	static void update(){ //update method pattern
		if(head_ == tail_) return;
		
		RessourceId resource = loadSound(pending_[head_].id);
		int channel = findOpenChannel();
		if(channel == -1) return;
		startSound(resource, channel, pending_[head_].volume);

		head_ = (head_ +1) % MAX_PENDING;
	}

private:
	static const int MAX_PENDING =16;
	
	static int head_;
	static int tail;
	static PlayMessage pending_[MAX_PENDING];

};

class Menu{
public:
	void onSelect(int index){
		Audio::playSound(SOUND_BLOB, VOL_MAX);
		//other stuff ...
	}

};