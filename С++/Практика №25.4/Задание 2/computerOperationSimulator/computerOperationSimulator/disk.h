#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "ram.h"

void save() {
	std::ofstream data("..\\data.txt");
	if(data.is_open()){
		for (size_t i = 0; i < buffer.size(); i++)
			data << read(i) << "\n";
		data.close();
	}
}

void load(int digit = 0) {
	std::ifstream data("..\\data.txt");
	if (data.is_open()) {
		buffer.clear();
		while (!data.eof()) {
			data >> digit;
			write(digit, 0);
		}
		data.close();
	}
}