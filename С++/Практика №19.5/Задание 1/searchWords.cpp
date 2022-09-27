#include <iostream>
#include <fstream>

// D:\\test\\words.txt

int main()
{
	std::string searchWord, path, word;
	int count = 0;
	std::cout << "Input path (\\->\\\\): ";
	std::cin >> path;
	std::ifstream data(path);
	std::cout << "Input word: ";
	std::cin >> searchWord;
	while (!data.eof())
	{
		data >> word;
		if(word == searchWord) count++;
	}
	data.close();
	std::cout << "Count: " << count << std::endl;
	return 0;
}