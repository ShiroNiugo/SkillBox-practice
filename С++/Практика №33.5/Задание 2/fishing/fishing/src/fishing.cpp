#include <iostream>
#include <ctime>
#include <exception>

#include "../field.h"
#include "../fish.h"

int main()
{
	srand(time(nullptr));
	Field *field = new Field[9];
	int area, count = 0;

	field[rand() % 9].fish = new Fish();
	for (int i = 0; i < 3; ) {
		int r = rand() % 9;
		if (field[r].fish == nullptr) {
			field[r].fish = new Fish("boot");
			i++;
		}
	}

	while (1) {
		printf("Input field (1-9): ");
		try {
			if (std::cin >> area && (area > 0 && area <= 9)) {
				count++;
				if (field[area - 1].find()) {
					printf("count: %i\n", count);
					break;
				}
			}
			else {
				std::cin.clear();
				std::cin.ignore();
				throw std::invalid_argument((area <= 0 || area > 9) ? "outside the array" : "invalid");
			}
		}
		catch (const std::invalid_argument e) {
			std::cerr << e.what() << std::endl;
		}
	}
	field = nullptr;
	delete field;
	return 0;
}