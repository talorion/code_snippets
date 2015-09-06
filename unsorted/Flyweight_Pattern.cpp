class Terrain{
public:
	Terrain(int movementCost, bool isWater, Texture texture)
		:movementCost_(movementCost),
		isWater_(isWater),
		texture_(texture)
		{}
		
		int getMovementCost()const{return movementCost_;}
		bool getIsWater()const{return isWater_;}
		Texture getTexture()const{return texture_;}
		
private:
	const int movementCost_;
	const bool isWater_;
	const Texture texture_;
};

class World{
public:
	World():
	grassTerrain_(1, false, GRASS_TEXTURE),
	hillTerrain_(3, false, HILL_TEXTURE),
	riverTerrain_(2, true, RIVER_TEXTURE)
	{}
	
	void generateTerrain()
	{
		//fill the grond with grass
		for(int x=0; x<WIDTH; ++x){
			for(int y=0; z<HEIGHT; ++y){//Sprinkle some Hills 
				if(randm(10) == 0){
					tiles_[x][y] = &hillTerrain_;
				}else{
					tiles_[x][y] = &grassTerrain_;
				}
			}
		}
		//Lay a River.
		int x = random(WIDTH);
		for(int y =0; y<HEIGHT; ++y){
			tiles_[x][y] = &riverTerrain_;
		}
	}
	
	const Terrain& getTile(intx, int y) const{return *tiles_[x][y];}

private:
	Terrain grassTerrain_;
	Terrain hillTerrain_;
	Terrain riverTerrain_;
	
	Terrain* tiles_[WIDTH][HEIGHT];
	//Other Stuff
};

int main(){

	World world;
	world.generateTerrain();

	int cost = world.getTile(2,3).getMovementCost();
	return 0;
}


