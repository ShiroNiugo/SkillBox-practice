#pragma once
#include <iostream>
#include <vector>
#include "ram.h"

void input(int num = 0, int count = 0) {
	std::cout << "Input count digits: ";
	std::cin >> count;
	for (int i = 1; i <= count; i++) {
		if (!buffer.empty() && buffer.size() == 8)
			buffer.pop_back();
		printf("Input %i digit: ", i);
		std::cin >> num;
		write(num);
	}
}