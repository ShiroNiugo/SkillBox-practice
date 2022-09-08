#include <iostream>
#include <vector>

int main()
{
	int n, count = 0;
	std::cout << "Input vector size: ";
	std::cin >> n;
	std::vector<int> numbers(n);
	std::cout << "Input numbers: ";
	for (size_t i = 0; i < numbers.size(); i++)
		std::cin >> numbers[i];
	std::cout << "Input number to delete: ";
	std::cin >> n;
	for (size_t i = 0, j = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == n)
		{
			count++;
		}
		else
		{
			numbers[j] = numbers[i];
			j++;
		}
	}
	for (; 0 < count; count--)
	{
		numbers.pop_back();
	}
	std::cout << "Result: ";
	for (auto num : numbers)
		std::cout << num << " ";
	std::cout << "\n";
}