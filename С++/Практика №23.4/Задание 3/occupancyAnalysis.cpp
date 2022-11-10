#include <iostream>
#include <vector>

#define RECORD(van)                                                               \
	for (size_t i = 0; i < van.size(); i++)                                       \
	{                                                                             \
		do                                                                        \
		{                                                                         \
			printf("Enter the number of passengers in wagon %i: ", (int)(i + 1)); \
			std::cin >> van[i];                                                   \
		} while (van[i] < 0);                                                     \
	}
#define ANALYSIS(van, crowdedWagons, emptyWagons, count)                                                  \
	for (size_t i = 0; i < van.size(); i++)                                                              \
	{                                                                                                    \
		if (van[i] - 20 > 0)                                                                             \
			crowdedWagons += "van " + std::to_string(i + 1) + ": " + std::to_string(van[i] - 20) + "\n";  \
		else if (van[i] < 20)                                                                            \
			emptyWagons += ("van " + std::to_string(i + 1) + ": " + std::to_string(20 - van[i]) + "\n"); \
		count += van[i];                                                                                 \
	}                                                                                                    \
	std::cout << crowdedWagons << emptyWagons << "Count: " << count;

int main()
{
	std::vector<int> van(10);
	int count = 0;
	std::string crowdedWagons = "Crowded wagons:\n", emptyWagons = "Empty seats in the wagons:\n";
	RECORD(van);
	ANALYSIS(van, crowdedWagons, emptyWagons, count);
	return 0;
}