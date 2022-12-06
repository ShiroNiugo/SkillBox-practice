#include <iostream>
#include "../cpu.h"
#include "../disk.h"
#include "../gpu.h"
#include "../kbd.h"

int main()
{
	std::string commands;
	while (1) {
		std::cout << "Input command: ";
		std::cin >> commands;
		if (commands == "sum") compute();
		else if (commands == "save") save();
		else if (commands == "load") load();
		else if (commands == "input") input();
		else if (commands == "display") display();
		else if (commands == "exit") break;
	}
	return 0;
}
