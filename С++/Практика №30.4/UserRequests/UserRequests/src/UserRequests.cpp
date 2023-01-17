// UserRequests.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <cpr/cpr.h>
#include "../get.h"
#include "../post.h"
#include "../put.h"
#include "../delete.h"
#include "../patch.h"

using namespace std;

int main()
{
	std::string commands;
	cpr::Response r;
	do{
		printf("%s", r.text.c_str());
		std::cout << "Input command: ";
		std::cin >> commands;
		if (commands == "get") r = get();
		else if (commands == "post") r = post();
		else if (commands == "put") r = put();
		else if (commands == "delete") r = del();
		else if (commands == "patch") r = patch();
	} while (commands != "exit");
	return 0;
}
