#include <iostream>
#include <string>
#include <map>
#include <exception>

#include "../market.h"
#include "../warehouse.h"
#include "../basket.h"

void filling(std::string& art, int& count) {
	printf("Input the article number: ");
	std::cin >> art;
	while (1) {
		printf("Input the product quantity: ");
		try {
			if (std::cin >> count) {
				break;
			}
			else {
				std::cin.clear();
				std::cin.ignore();
				throw std::invalid_argument("Invalid");
			}
		}
		catch (const std::invalid_argument e) {
			std::cout << e.what() << std::endl;
		}
	}
}

int main()
{
	std::string command, art;
	int count;
	Market* warehouse = new Warehouse();
	Market* basket = new Basket();

	printf("Shop\nFilling warehouse\n");
	for (int i = 0; i < 5; i++)
	{
		filling(art, count);
		warehouse->add(art, count);
	}

	warehouse->show();

	printf("Basket\n");
	do {
		printf("Input command: ");
		std::cin >> command;
		try
		{
			if (command == "add")
			{
				filling(art, count);
				warehouse->remove(art, count);
				basket->add(art, count);
			}
			else if (command == "remove") {
				filling(art, count);
				basket->remove(art, count);
				warehouse->add(art, count);
			}
		}
		catch (const std::runtime_error e)
		{
			std::cerr << e.what() << std::endl;
		}
		basket->show();
		std::cout << std::endl;
		warehouse->show();
	} while (command != "exit");
	delete warehouse, basket;
	return 0;
}