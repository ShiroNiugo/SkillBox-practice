#include <iostream>

int main()
{
	int fork[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};
	int spoon[2][6] = {{2, 1, 1, 1, 1, 1}, {2, 1, 1, 1, 1, 1}};
	int knife[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};
	int plates[2][6] = {{3, 2, 2, 2, 2, 2}, {3, 2, 2, 2, 2, 2}};
	int chairs[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};

	chairs[0][4] += 1;
	spoon[0][2] -= 1;
	spoon[0][0] -= 1;
	spoon[0][2] += 1;
	plates[0][0] -= 1;

	std::cout << "fork:\t";
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 6; j++)
			std::cout << fork[i][j] << " ";
	std::cout << std::endl;

	std::cout << "spoon:\t";
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 6; j++)
			std::cout << spoon[i][j] << " ";
	std::cout << std::endl;

	std::cout << "knife:\t";
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 6; j++)
			std::cout << knife[i][j] << " ";
	std::cout << std::endl;

	std::cout << "plates:\t";
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 6; j++)
			std::cout << plates[i][j] << " ";
	std::cout << std::endl;

	std::cout << "chairs:\t";
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 6; j++)
			std::cout << chairs[i][j] << " ";
	std::cout << std::endl;

	return 0;
}