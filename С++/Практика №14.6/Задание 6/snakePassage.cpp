#include <iostream>

int main()
{
	int digits[5][5], number = 0, multiplier = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++, multiplier++, number++)
			digits[i][abs(multiplier)] = number;
		for (int j = 0; j < 5; j++)
			std::cout << digits[i][j] << " ";
		multiplier -= multiplier%2;
		multiplier *= -1;
		std::cout << std::endl;
	}
	return 0;
}