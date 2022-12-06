#pragma once
#include <iostream>
#include <vector>
#include "ram.h"

void compute(int sum = 0) {
	for (size_t i = 0; i < buffer.size(); i++)
		sum += read(i);
	printf("Summa digits: %i", sum);
}