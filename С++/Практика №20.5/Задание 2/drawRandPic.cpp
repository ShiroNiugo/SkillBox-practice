#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

// D:\\test\\pic.txt

int main()
{
	int width, height;
	std::cout << "Input width and height: ";
	std::cin >> width >> height;

	std::ofstream pic("D:\\test\\pic.txt");
	std::srand(std::time(nullptr));
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
			pic << std::rand()%2;
		pic << std::endl;
	}
	pic.close();
	return 0;
}