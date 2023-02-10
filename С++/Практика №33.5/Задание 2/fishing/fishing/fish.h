#pragma once

class Fish {
	std::string name;
public:
	std::string getName() {
		return name;
	}
	Fish(std::string inName) : name(inName) {}
	Fish() : Fish("fish") {}
	~Fish() {}
};