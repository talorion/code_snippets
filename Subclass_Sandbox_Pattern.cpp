class Superpower{
public: 
	virtual ~Superpower(){}
	
protected:
	virtual void activate()=0;
	
	double getHeroX(){ /* code here */}
	
	double getHeroY(){ /* code here */}
	
	double getHeroZ(){ /* code here */}
	
	void move(double x, double y, double z){ /* code here */}
	
	void playSound(SoundId sound, double voulume){ /* code here */}
	
	void spawnParticles(ParticleType type, int count){ /* code here */}
};

class SkyLaunch : public Superpower{
protected:
	virtual void activate(){
		if(getHeroZ() ==0){
			//Spring into the air.
			playSound(SOUND_SPROING, 1.0f);
			spawnParticles(PARTICLE_DUST, 10);
			move(0, 0, 20);
		}else if(getHeroZ() < 10.0f){
			//Near ground, so do a double jump
			playSound(SOUND_SWOOP, 1.0f);
			move(0, 0, getHeroZ()-20);
		}else{
			//Way up in the air, so do a dive attack
			playSound(SOUND_DIVE, 0.7f);
			spawnParticles(PARTICLE_SPARKLES, 10);
			move(0, 0, -getHeroZ());
		}
	}

};