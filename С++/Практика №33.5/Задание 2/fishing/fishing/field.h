#pragma once

#include "fish.h"

class Field {
public:
	Fish* fish = nullptr;

	bool find() {
		try {
			if (fish != nullptr) {
				printf("%s, ", fish->getName().c_str());
				return true;
			}
			else 
				throw std::invalid_argument("empty");
		}
		catch (const std::invalid_argument e) {
			std::cerr << e.what() << std::endl;
			return false;
		}
	}

	Field(Fish* inFish) : fish(inFish) {}
	Field() : Field(nullptr) {}
	~Field() {
		delete fish;
	}
};