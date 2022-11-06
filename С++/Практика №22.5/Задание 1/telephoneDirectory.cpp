#include <iostream>
#include <string>
#include <map>

std::string format(int telephone)
{
	return std::to_string(telephone).substr(0, 2) + "-" + std::to_string(telephone).substr(2, 2) + "-" + std::to_string(telephone).substr(4, 2);
}

void add(std::map<int, std::string> &directory)
{
	int telephone;
	std::string secondName;
	do
	{
		printf("Input telephone and second name: ");
		std::cin >> telephone >> secondName;
	} while ((int)std::to_string(telephone).length() != 6);
	directory[telephone] = secondName;
}

void find(std::map<int, std::string> directory, int oper)
{
	std::string discover;
	printf("Input %s: ", (oper == 2 ? "telephone" : "second name"));
	std::cin >> discover;
	for (std::map<int, std::string>::iterator it = directory.begin(); it != directory.end(); it++)
		std::cout << ((oper == 2 && it->first == stoi(discover)) ? (it->second + " ")
					: (oper == 3 && it->second == discover) ? (format(it->first) + " "):"");
	std::cout << std::endl;
}

int main()
{
	std::map<int, std::string> directory;
	int operation;
	do
	{
		printf("Operation (1 - add a subscriber , 2 - find by telephone, 3 - find by second name, 4 - exit): ");
		std::cin >> operation;
		if (operation == 1)
			add(directory);
		else if (operation == 2 || operation == 3)
			find(directory, operation);
	} while (operation != 4);
}