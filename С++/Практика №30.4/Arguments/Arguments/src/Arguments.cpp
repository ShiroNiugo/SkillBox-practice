#include <iostream>
#include <map>
#include <vector>
#include "cpr/cpr.h"

using namespace std;

int main()
{
	std::map<std::string, std::string> arguments;
	std::string first, second, command;
	for (int i = 0; i < 3; i++) {
		printf("Input [%i] key and value: ", (i + 1));
		cin >> first >> second;
		arguments[first] += second;
	}

	cout << "Input get or post: ";
	cin >> command;

	cpr::Response r;
	if(command == "get"){
		std::string add = "?";
		for (auto& [key, value] : arguments)
			add += key + "="+value+(key.size() == key.back() ? "" : "&");
		r = cpr::Get(cpr::Url("http://httpbin.org/get"+add));
	}
	else if(command == "post"){
		std::vector<cpr::Pair> p;
		for (auto& [key, value] : arguments)
			p.push_back(cpr::Pair(key.c_str(), value.c_str()));
		r = cpr::Post(cpr::Url("http://httpbin.org/post"), cpr::Payload({ p.begin(), p.end()}));
	}
	printf("%s", r.text.c_str());
	return 0;
}
