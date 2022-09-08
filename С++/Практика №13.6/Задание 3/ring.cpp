#include <iostream>
#include <vector>

int main()
{
	int number, numberStart = 0;
	std::vector<int> ringNumbers(20);
	for (size_t i = 0;; (i < ringNumbers.size()-1) ? (i++) : (i = 0))
	{
		std::cout << "input number: ";
		std::cin >> number;
		if (number < 0)
			break;
		if(ringNumbers[i] != 0) numberStart++;
		ringNumbers[i] = number;
	}
	std::cout << "output: ";
	for (size_t i = numberStart, count = 0; count < ringNumbers.size(); ((i < ringNumbers.size()-1) ? (i++) : (i = 0)), count++)
	{
		if (ringNumbers[i] != 0)
			std::cout << ringNumbers[i] << "  ";
	}
	std::cout << "\n";
}