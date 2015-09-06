class Framebuffer{
public:
	Framebuffer(){clear();}
	
	void clear(){
		for(int i=0; i<WIDTH*HEIGHT; ++i){
			pixels_[i] = WHITE
		}
	}
	
	void draw(int x, int y){
		pixels_[(WIDTH*y)+x] = BLACK;
	}
	
	const char* getPixels(){
		return pixels_;
	}
	
private:
	const int WIDTH 	= 160;
	const int HEIGHT 	= 120;
	
	char pixels[WIDTH*HEIGHT];
	
};

class Scene
{
public:
	Scene():
	current_(&buffers[0]),
	next_(&buffers[0]),

	void draw(){
		next_.clear();
		
		next_.draw(1,1);
		next_.draw(4,1);
		next_.draw(1,3);
		next_.draw(2,4);
		next_.draw(3,4);
		next_.draw(4,3);
		
		swap();
	}
	
	const Framebuffer& getBuffer(){return current_;}
	
private:
	void swap(){
		//Just switch pointers
		Framebuffer* temp 	= current_;
		current_ 			= next_;
		next_ 				= temp;
	}
		
private:
	Framebuffer buffers[2];
	Framebuffer* current_;
	Framebuffer* next_;
};
	