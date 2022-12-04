#include <iostream>
#include <string>
#include "../include/command.h"

void addOneCoord(int& x, int& y)
{
	double coord;
	do
	{
		printf("Input coordination (x,y): ");
		std::cin >> coord;
		x = (int)coord;
		y = (coord - x + 0.0000001) * 10;
	} while (body[x][y] != '.');
}

void addTwoCoord(int& x, int& y, int& x2, int& y2)
{
	double coord;
	for (int i = 1; i <= 2;)
	{
		do
		{
			printf("Input %i coordination (x,y): ", i);
			std::cin >> coord;
			(i == 1 ? x : x2) = (int)coord;
			(i == 1 ? y : y2) = (coord - (i == 1 ? x : x2) + 0.0000001) * 10;
		} while (body[(i == 1 ? x : x2)][(i == 1 ? y : y2)] != '.');
		i++;
	}
}

int main()
{
	std::string command;
	int x, y, x2, y2;
	fill();
	while (1)
	{
		std::cout << "Input command: ";
		std::cin >> command;
		if (command == "scalpel")
		{
			addTwoCoord(x, y, x2, y2);
			scalpel(x, y, x2, y2);
		}
		else if (command == "hemostat")
		{
			addOneCoord(x, y);
			hemostat(x, y);
		}
		else if (command == "tweezers")
		{
			addOneCoord(x, y);
			tweezers(x, y);
		}
		else if (command == "suture")
		{
			addTwoCoord(x, y, x2, y2);
			suture(x, y, x2, y2);
			break;
		}
	}
	return 0;
}