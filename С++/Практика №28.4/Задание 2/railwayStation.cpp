#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex trainAccess;

void timer(std::string train, int time)
{
	std::this_thread::sleep_for(std::chrono::seconds(time));
	trainAccess.lock();
	printf("Train %s arrived at the train station\n", train.c_str());
	std::string command;
	do
	{
		std::cout << "Input command: ";
		std::cin >> command;
	} while (command != "depart");
	trainAccess.unlock();
}

int main()
{
	int seconds;
	std::vector<int> train;
	for (int i = 0; i < 3; i++)
	{
		do
		{
			printf("Input the number of seconds for train %i: ", (i + 1));
			std::cin >> seconds;
		} while (seconds <= 0);
		train.push_back(seconds);
	}

	std::thread trainA(timer, "A", train[0]);
	std::thread trainB(timer, "B", train[1]);
	std::thread trainC(timer, "C", train[2]);
	trainA.join();
	trainB.join();
	trainC.join();

	return 0;
}