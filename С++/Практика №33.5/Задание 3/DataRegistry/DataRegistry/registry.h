#pragma once

template<typename Key, typename Value>
class Registry
{
	struct Data
	{
		Key key;
		Value value;
	};
	Key k;
	Value v;
	std::vector<Data> data;
public:
	void add() {
		printf("Input key and value: ");
		if (std::cin >> k >> v) {
			data.push_back({ k, v });
		}
		else {
			std::cin.clear();
			std::cin.ignore();
			throw std::invalid_argument("invalid argument");
		}
	}
	void remove() {
		printf("Input key: ");
		if (std::cin >> k)
		{
			for (auto itf = data.begin(); itf != data.end();) {
				if (itf->key == k) data.erase(itf);
				else itf++;
			}
		}
		else {
			std::cin.clear();
			std::cin.ignore();
			throw std::invalid_argument("invalid argument");
		}
	}
	void print() {
		for (auto d : data)
			std::cout << "key: " << d.key << ", value: " << d.value << std::endl;
	}
	void find() {
		printf("Input key: ");
		if (std::cin >> k)
		{
			for (auto d : data) {
				if (d.key == k)
					std::cout << "value: " << d.value << std::endl;
			}
		}
		else {
			std::cin.clear();
			std::cin.ignore();
			throw std::invalid_argument("invalid argument");
		}
	}
};