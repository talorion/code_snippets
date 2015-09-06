int main(){

	double current=0.0;
	double elapsed=0.0;
	double previous= getCurrentTime();
	double lag=0.0;
	
	while(true){
		current = getCurrentTime();
		elapsed = current - previous;
		previous= current;
		
		lag += elapsed;
	
		processInput();
		
		while(lag >= MS_PER_UPDATE){
			update();
			lag -= MS_PER_UPDATE;
		}
		render(lag / MS_PER_UPDATE);
	}
	
	return 0;
}