#include <iostream>
#include <vector>
#include <string>
#include <exception>

#include "../registry.h"

template<typename Data>
void commands(Data data) {
	std::string command;
	do {
		try {
			printf("Input command: ");
			std::cin >> command;
			if (command == "add") { data->add(); }
			else if (command == "remove") data->remove();
			else if (command == "print") data->print();
			else if (command == "find") data->find();
		}
		catch (const std::invalid_argument e) {
			std::cerr << e.what() << std::endl;
		}
	} while (command != "exit");
}

int main()
{
	printf("Key: string, Value: int\n");
	Registry<std::string, int>* data = new Registry<std::string, int>();
	commands(data);
	delete data;

	printf("Key: int, Value: double\n");
	Registry<int, double>* data2 = new Registry<int, double>();
	commands(data2);
	delete data2;

	return 0;
}