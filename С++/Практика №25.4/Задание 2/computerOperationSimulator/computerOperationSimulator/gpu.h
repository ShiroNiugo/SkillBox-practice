#pragma once
#include <iostream>
#include <vector>
#include "ram.h"

void display() {
	for (size_t i = 0; i < buffer.size(); i++)
		printf("%i ", read(i));
	std::cout << std::endl;
}