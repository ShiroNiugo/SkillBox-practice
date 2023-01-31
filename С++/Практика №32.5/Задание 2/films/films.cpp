#include <iostream>
#include <fstream>
#include <vector>

#include <nlohmann/json.hpp>
#include "bd.h"

using namespace std;
using json = nlohmann::json;

void searchActors(json src, std::string name, std::vector<std::string> arr, std::string film = "") {
	for (auto& [key, value] : src.items()) {
		auto roles = value.find("roles");
		if (roles != value.end())
			searchActors(roles.value(), name, arr, key+": ");
		else {
			std::string n = (value.is_string()) ? value : "";
			if (n.find(name) != std::string::npos)
				arr.push_back(key);//std::cout << film << key << std::endl;
		}
	}
	if(!arr.empty())
		for(auto i : arr)
			printf((i != arr.back() ? "%s, " : "%s\n"), (i == arr.front() ? (film + i).c_str() : i.c_str()));
}

int main()
{
	createBD();
	std::ifstream input("../file.json");
	if (input.is_open()) {
		json filmsInput;
		input >> filmsInput;
		input.close();
		std::string command;

		while (1) {
			std::cout << "Actor search (by first name or last name): ";
			std::cin >> command;
			if (command != "exit") { searchActors(filmsInput, command, std::vector<std::string>()); }
			else { break; }
		}
	}
	return 0;
}
