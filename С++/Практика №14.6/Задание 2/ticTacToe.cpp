#include <algorithm>
#include <iostream>

bool result(char grid[][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (((grid[0][0] == 'X' || grid[0][0] == 'O') && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) ||
				((grid[0][2] == 'X' || grid[0][2] == 'O') && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) ||
				((grid[i][0] == 'X' || grid[i][0] == 'O') && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) ||
				((grid[0][j] == 'X' || grid[0][j] == 'O') && grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j]))
				return true;
	return false;
}

void grating(char grid[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << grid[i][j] << (j < 2 ? "|" : "");
		std::cout << std::endl;

		for (int j = 0; j < 3; j++)
			std::cout << ((i < 2 && j < 2) ? "-+" : (i < 2 && j == 2) ? "-"
																	  : "");
		std::cout << std::endl;
	}
}

int main()
{
	char grid[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	for (int move = 0, player = 0;;)
	{
		grating(grid);
		int row, column;
		do
		{
			std::cout << (player == 0 ? "Player 1 " : "Player 2 ") << "(row, column): ";
			std::cin >> row >> column;
		} while (row <= 0 || row > 3 || column <= 0 || column > 3);
		row--;
		column--;
		if (grid[row][column] == ' ')
		{
			grid[row][column] = (player == 0 ? 'X' : 'O');
			move++;
			if (result(grid) == true)
			{
				grating(grid);
				std::cout << "Win - " << (player == 0 ? "Player 1 " : "Player 2 ") << std::endl;
				break;
			}
			else if (move > 8)
			{
				grating(grid);
				std::cout << "Nobody" << std::endl;
				break;
			}
		}
		else
			std::cout << "the cell is full" << std::endl;
		player = (player == 0 ? 1 : 0);
	}
	return 0;
}