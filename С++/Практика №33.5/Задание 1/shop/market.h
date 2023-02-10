#pragma once

class Market
{
protected:
	std::map<std::string, int> container;
public:
	void show() {
		for (auto& [key, value] : container)
			printf("%s = %i\n", key.c_str(), value);
	}
	void add(std::string art, int count)
	{
		container[art] += count;
	}
	virtual void remove(std::string art, int count) = 0;
};