#pragma once
#include <iostream>
#include <cmath>

char body[10][10];

void fill()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			body[i][j] = '.';
}

void show()
{
	std::cout << "  ";
	for (int i = 0; i < 10; i++)
		std::cout << i << " ";
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " ";
		for (int j = 0; j < 10; j++)
			std::cout << body[i][j] << " ";
		std::cout << std::endl;
	}
}

void bresenhamAlgorithm(char ch, int x1, int y1, int x2, int y2)
{
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;
	int error = deltaX - deltaY;
	body[x2][y2] = ch;
	while (x1 != x2 || y1 != y2)
	{
		body[x1][y1] = ch;
		int error2 = error * 2;
		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}
}

void scalpel(int x1, int y1, int x2, int y2)
{
	bresenhamAlgorithm('s', x1, y1, x2, y2);
	show();
}

void hemostat(int x, int y)
{
	body[x][y] = 'h';
	show();
}

void tweezers(int x, int y)
{
	body[x][y] = 't';
	show();
}
void suture(int x1, int y1, int x2, int y2)
{
	bresenhamAlgorithm('S', x1, y1, x2, y2);
	show();
}