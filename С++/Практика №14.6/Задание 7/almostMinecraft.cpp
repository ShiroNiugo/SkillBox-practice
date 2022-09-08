#include <iostream>

int maxLevel(int a, int b){
	return (a>b)?a:b;
}

int main()
{
	int max, almost[5][5][10];
	std::cout << "input matrix of heights: \n";

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			int num;
			std::cin >> num;
			max = maxLevel(max, num);
			for (int level = 0; level < 10; level++, num--)
				almost[i][j][level] = (num >= 0 ? 1 : 0);
		}

	int level;
	do{
		std::cout << "input slice: ";
		std::cin >> level;
	}while(level <= 0 || max < level);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			std::cout << (almost[i][j][level] ? 1 : 0) << " ";
		std::cout << std::endl;
	}
	return 0;
}