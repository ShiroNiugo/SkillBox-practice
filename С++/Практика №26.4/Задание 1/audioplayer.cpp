#include <iostream>
#include <ctime>

class Track{
	std::string name;
	std::time_t date;
	int time;
	public:
		std::string getName(){
			return name;
		}
		std::tm* getDate(){
			return std::localtime(&date);
		}
		int getTime(){
			return time;
		} 

		void setName(std::string nameTrack){
			 name = nameTrack;
		}
		void setDate(std::time_t dateTrack){
			date = dateTrack;
		}
		void setTime(int timeTrack){
			time = timeTrack;
		} 
};

int main(){
	std::srand(std::time(nullptr));
	int size = rand() % 10 + 3;
	Track *tracks = new Track[size];
	for(int i = 0; i < size; i++){
		tracks[i].setName("Track N"+std::to_string(i+1));
		tracks[i].setDate(rand());
		tracks[i].setTime(rand()%300+60);
	}
	std::string command;
	enum player{
		PLAY = 1,
		PAUSE = 2,
		STOP = 4
	};
	int player_state = 0, digitTrack;
	while(1){
		std::cout << "Input command: ";
		std::cin >> command;

		if((!(player_state & PLAY)) && command == "play"){
			if(!(player_state & PAUSE))
				digitTrack = rand() % size;
			player_state |= PLAY;
			player_state &= ~PAUSE;
			player_state &= ~STOP;
			std::cout << "The track is playing\n" << "Name: " << tracks[digitTrack].getName().c_str() << ", time: " << tracks[digitTrack].getTime() << ", date: " << std::asctime(tracks[digitTrack].getDate());
		}
		
		else if((player_state & PLAY) && !(player_state & STOP) && !(player_state & PAUSE) && command == "pause"){
			player_state &= ~PLAY;
			player_state |= PAUSE;
			std::cout << "Track on pause\n" << "Name: " << tracks[digitTrack].getName().c_str() << ", time: " << tracks[digitTrack].getTime() << ", date: " << std::asctime(tracks[digitTrack].getDate());
		}
		
		else if(((player_state & PLAY) || (player_state & PAUSE)) && command == "next"){
			int num;
			do{
				num = (rand() % size);
			}while(digitTrack == num);
			digitTrack = num;
			std::cout << "Next track\n" << "Name: " << tracks[digitTrack].getName().c_str() << ", time: " << tracks[digitTrack].getTime() << ", date: " << std::asctime(tracks[digitTrack].getDate());
		}
		
		else if(((player_state & PLAY) || (player_state & PAUSE)) && !(player_state & STOP) && command == "stop"){
			player_state &= ~PLAY;
			player_state &= ~PAUSE;
			player_state |= STOP;
			std::cout << "Track discontinued\n" << "Name: " << tracks[digitTrack].getName().c_str() << ", time: " << tracks[digitTrack].getTime() << ", date: " << std::asctime(tracks[digitTrack].getDate());
		}
		
		if(command == "exit"){
			break;
		}
	}
	delete []tracks;
	return 0;
}