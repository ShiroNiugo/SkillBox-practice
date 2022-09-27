#include <iostream>
#include <fstream>

// D:\\test\\words.txt

int main()
{
	char buffer[20];
	std::string path;
	std::cout << "Input path (\\->\\\\): ";
	std::cin >> path;
	std::ifstream data(path, std::ios::binary);
	if (data.is_open())
	{
		while (!data.eof())
		{
			int size = data.read(buffer, sizeof(buffer)).gcount();
			for(int i = 0; i < size; i++)
				std::cout << buffer[i];
		}
		std::cout << std::endl;
		data.close();
	}
	return 0;
}