#include <iostream>
#include <string>
#include <map>

void add(std::map<std::string, int> &queue){
	std::string secondName;
	std::cout << "<- ";
	std::cin >> secondName;
	if(secondName == "Next"){
		printf("-> %s\n", queue.begin()->first.c_str());
		if(queue.begin()->second == 1) queue.erase(queue.begin());
		else queue.begin()->second--;
	}else{
		queue[secondName]++;
	}
}

int main(){
	std::map<std::string, int> queue;
	add(queue);
	do{
		add(queue);
	}while(queue.size() != 0);
	return 0;
}