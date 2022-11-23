#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <sstream>

std::string stime(time_t t)
{
	std::stringstream convert;
	std::tm *local = std::localtime(&t);
	convert << std::put_time(local, "%d/%m/%Y %H:%M");
	return convert.str() + " ";
}

void end(time_t t, std::vector<std::string> &tasks, time_t t2 = std::time(nullptr))
{
	if (!tasks.empty())
		tasks.back() += " " + std::to_string(std::difftime(t2, t)/60*100/100) + " completed";
}

int main()
{
	std::string command, task;
	std::vector<std::string> tasks;
	std::time_t t;
	do
	{
		std::cout << "Input command: ";
		std::cin >> command;
		if (command == "begin")
		{
			std::cout << "Input task: ";
			std::cin >> task;
			end(t, tasks);
			t = std::time(nullptr);
			tasks.push_back(stime(t) + task);
		}
		else if (command == "end")
			end(t, tasks);
		else if (command == "status")
			for (auto s : tasks)
				std::cout << s << std::endl;
	} while (command != "exit");
}