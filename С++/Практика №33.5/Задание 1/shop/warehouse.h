#pragma once
#include "market.h"

class Warehouse : public Market
{
public:
	void remove(std::string art, int count) override
	{
		if (container.find(art)->second - count >= 0)
			container[art] -= count;
		else
			throw std::runtime_error("The quantity in stock is less than you can pick up");
	}
};