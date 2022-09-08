#include <iostream>

void show(bool grid[][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			std::cout << (grid[9 - i][j] ? "X" : "~") << " ";
		std::cout << std::endl;
	}
}

bool field(bool grid[][10], int x1, int y1, int x2, int y2)
{
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++)
			if (grid[i][j])
				return false;

	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++)
			grid[i][j] = true;

	show(grid);

	return true;
}

void placement(bool field_1[][10], bool field_2[][10])
{
	for (int box = 0; box < 2; box++)
	{
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				(box == 0 ? field_1[i][j] : field_2[i][j]) = false;

		for (int size = 1, cell = 1; size <= 4; (cell <= 5 - size) ? (cell) : (size++, cell = 1))
		{
			int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
			if (size == 1)
				do
				{
					std::cout << (box == 0 ? "Player 1 - " : "Player 2 - ") << size << " size " << cell << " ship: ";
					std::cin >> x1 >> y1;
				} while ((x1 <= 0 || x1 > 11) || (y1 <= 0 || y1 > 11));
			else
				do
				{
					std::cout << (box == 0 ? "Player 1 - " : "Player 2 - ") << size << " size " << cell << " ship: ";
					std::cin >> x1 >> y1 >> x2 >> y2;
				} while ((x1 <= 0 || x1 > 11) || (x2 <= 0 || x2 > 11) || (y1 <= 0 || y1 > 11) || (y2 <= 0 || y2 > 11) || abs(x2 - x1) + abs(y2 - y1) + 1 != size);
			x1--;
			y1--;
			x2--;
			y2--;
			if (((size == 1) ? field((box == 0 ? field_1 : field_2), x1, y1, x1, y1)
						   	 : field((box == 0 ? field_1 : field_2), ((x1 <= x2) ? x1 : x2), ((y1 <= y2) ? y1 : y2), ((x1 <= x2) ? x2 : x1), ((y1 <= y2) ? y2 : y1))) &&
				cell <= 5 - size)
				cell++;
		}
	}
}

bool winPlayer(bool grid[][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; i < 10; j++)
			if (grid[i][j])
				return true;
	return false;
}

int main()
{
	bool field_1[10][10];
	bool field_2[10][10];

	placement(field_1, field_2);

	std::cout << "Play" << std::endl;
	for (int box = 0;; (box == 0 ? box++ : box = 0))
	{
		int x, y;
		do
		{
			std::cout << (box == 0 ? "Player 1 - " : "Player 2 - ") << "input coordinates: ";
			std::cin >> x >> y;
		} while ((x <= 0 || x > 11) || (y <= 0 || y > 11));
		x--;
		y--;
		std::cout << ((box == 0 ? field_2[x][y] : field_1[x][y]) ? "hit" : "not hit") << std::endl;
		(box == 0 ? field_2[x][y] : field_1[x][y]) = false;
		//show((box == 0 ? field_2 : field_1));
		if (!winPlayer(box == 0 ? field_2 : field_1))
		{
			std::cout << (box == 0 ? "Win Player 1" : "Win Player 2") << std::endl;
			break;
		}
	}
	return 0;
}