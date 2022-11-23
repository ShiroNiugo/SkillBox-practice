#include <iostream>
#include <ctime>
#include <iomanip>

int main()
{
	std::cout << "Input timer (MM:SS): ";
	std::time_t t = std::time(nullptr);
	std::tm local = *std::localtime(&t);
	std::cin >> std::get_time(&local, "%M:%S");
	t = std::mktime(&local);
	std::time_t end = std::time(nullptr);
	std::tm localEnd = *std::localtime(&end);
	localEnd.tm_sec += (local.tm_min*60)+local.tm_sec;
	end = std::mktime(&localEnd);	
	int curTime = -1;
	while(1){
		if(curTime != (int)(end-std::time(nullptr)) && curTime != 0){
			printf("%i:%i\n", (int)(end-std::time(nullptr))/60, (int)(end-std::time(nullptr))%60);
			curTime = (int)(end-std::time(nullptr));
		}else if ((int)(end-std::time(nullptr)) == 0){
			printf("DING! DING! DING!\n");
			break;	
		}
	}
	return 0;
}