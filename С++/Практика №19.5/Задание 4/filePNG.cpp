#include <iostream>
#include <fstream>
#include <string>

// D:\\test\\1663934199531.png

int main()
{
	char buffer[4];
	std::string path;
	std::cout << "Input path (\\->\\\\): ";
	std::cin >> path;
	std::ifstream data(path, std::ios::binary);
	if (data.is_open())
	{
		data.read((char *)buffer, sizeof(buffer));
		std::cout << (path.substr(path.size()-4,4) == ".png" && (buffer[0] == -119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G') ? "File png" : "File not png") << std::endl;
		data.close();
	}
	return 0;
}