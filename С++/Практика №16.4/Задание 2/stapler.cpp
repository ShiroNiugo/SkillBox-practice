#include <iostream>
#include <string>

int main()
{
	std::string integer, fraction;
	std::cout << "Input integer: ";
	std::cin >> integer;
	std::cout << "Input fraction: ";
	std::cin >> fraction;
	double result = std::stod(integer + "." + fraction);
	std::cout << result << std::endl;
	return 0;
}