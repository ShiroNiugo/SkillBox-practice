#include <iostream>
#include <string>
#include <sstream>

int main()
{
	std::string buffer;
	char operation;
	double a, b;
	std::cout << "Input a string in the form '<number-1><action><number-2>' (without spaces): ";
	std::cin >> buffer;
	std::stringstream buffer_stream(buffer);
	buffer_stream >> a >> operation >> b;
	std::cout << "Output: " << (operation == '+' ? (a + b) : operation == '-' ? (a - b)
										   	 : operation == '/' ? (a / b)
																: (a * b))
			  << std::endl;
	return 0;
}