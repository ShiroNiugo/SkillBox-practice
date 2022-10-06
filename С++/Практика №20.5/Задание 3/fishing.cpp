#include <iostream>
#include <fstream>
#include <map>

// D:\\test\\river.txt

int main()
{
	std::string path, fish;
	std::map<std::string, int> bas;

	std::cout << "Input path (\\ -> \\\\): ";
	getline(std::cin, path);
	std::ifstream river(path);
	if (river.is_open())
	{
		while (!river.eof())
		{
			river >> fish;
			bas[fish] += 1;
		}
		std::ofstream basket("D:\\test\\basket.txt");
		for (auto f : bas)
			basket << f.first << " " << f.second << std::endl;
	}
	return 0;
}