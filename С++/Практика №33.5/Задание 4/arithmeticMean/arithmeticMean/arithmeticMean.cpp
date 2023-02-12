#include <iostream>
#include <string>
#include <exception>

template <typename T>
void input(T array[8])
{
	std::cout << "Fill the array (8): ";
	for (int i = 0; i < 8; ++i)
	{
		while (1)
		{
			try
			{
				if (std::cin >> array[i])
					break;
				else
				{
					std::cin.clear();
					std::cin.ignore();
					throw std::invalid_argument("invalid argument " + std::to_string(i + 1));
				}
			}
			catch (const std::invalid_argument e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
	}
}

template <typename T>
T output(T array[8], T temp = 0) {
	for (int i = 0; i < 8; ++i) {
		temp += array[i];
	}
	return temp / 8;
}

int main()
{
	int arr1[8];
	std::cout << "Array int: ";
	input(arr1);
	std::cout << output(arr1) << std::endl;

	double arr2[8];
	std::cout << "Array double: ";
	input(arr2);
	std::cout << output(arr2) << std::endl;

	float arr3[8];
	std::cout << "Array float: ";
	input(arr3);
	std::cout << output(arr3) << std::endl;
	return 0;
}