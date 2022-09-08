#include <iostream>
#include <algorithm>

std::string result(std::string grid)
{
	for (auto ch : grid)
		if (!(ch == 'X' || ch == 'O' || ch == '.'))
			return "Incorrect";

	int x = std::count(grid.begin(), grid.end(), 'X'), o = std::count(grid.begin(), grid.end(), 'O');
	if ((x < o && x + 1 != o) || (x > o && x != o + 1))
		return "Incorrect";

	for (size_t i = 0; i < 9; i++)
		if (grid[i] == 'X' || grid[i] == 'O')
			if ((i == 0 && (grid[i] == grid[i + 4] && grid[i + 4] == grid[i + 8])) ||
				(i == 2 && (grid[i] == grid[i + 2] && grid[i + 2] == grid[i + 4])) ||
				((i == 0 || i == 3 || i == 6) && (grid[i] == grid[i + 1] && grid[i + 1] == grid[i + 2])) ||
				((i == 0 || i == 1 || i == 2) && (grid[i] == grid[i + 3] && grid[i + 3] == grid[i + 6])))
				return ((grid[i] == 'X' && x > o) ? "Petya won." : ((grid[i] == 'O' && x < o) ? "Vasya won." : "Incorrect"));

	return "Nobody";
}

int main()
{
	std::string first, second, third;
	do
	{
		std::cin >> first;
		std::cin >> second;
		std::cin >> third;
		if (first.size() != 3 || second.size() != 3 || third.size() != 3)
			std::cout << "\nGrid 3x3\n" << std::endl;
	} while (first.size() != 3 || second.size() != 3 || third.size() != 3);
	std::cout << "Result: " << result(first + second + third) << std::endl;
}