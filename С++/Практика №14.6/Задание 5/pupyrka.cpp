#include <iostream>

void initial(bool grid[][12])
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
			grid[i][j] = true;
}

void showGrid(bool grid[][12])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			std::cout << ((grid[i][j]) ? "O" : "X");
			std::cout << (j < 11 ? "|" : "");
		}
		std::cout << std::endl;
		if (i < 11)
		{
			for (int j = 0; j < 12; j++)
				std::cout << (j < 11 ? "-+" : "-");
			std::cout << std::endl;
		}
	}
}

bool check(bool grid[][12]){
	for(int i = 0; i < 12; i++)
		for(int j = 0; j < 12; j++)
			if(grid[i][j])
				return false;
	return true;
}

int main()
{
	bool grid[12][12];
	initial(grid);
	while (1)
	{
		showGrid(grid);
		if (check(grid)) break;
		int row, col;
		do
		{
			std::cout << "Input (row, column): ";
			std::cin >> row >> col;
		} while ((row <= 0 || row > 12) || (col <= 0 || col > 12));
		row--;
		col--;
		std::cout << (grid[row][col] ? grid[row][col] = false, "Pop!" : "") << std::endl;
	}
}