#pragma once
#include <iostream>
#include <vector>

std::vector<int> buffer;

void write(int digit, bool start = 1) {
	if (start) buffer.insert(buffer.begin(), digit);
	else buffer.insert(buffer.end(), digit);
}

int read(int i) {
	return buffer.at(i);
}