#include <iostream>
#include <ctime>
#include <iomanip>
#include <map>

int main()
{
	std::map<std::time_t, std::string> birthday;
	std::string name;
	std::time_t t = std::time(nullptr), current = std::time(nullptr);
	std::tm local = *std::localtime(&t), curDate = *std::localtime(&current);
	while (true)
	{
		std::cout << "Input name: ";
		std::cin >> name;
		if (name == "end")
			break;
		std::cout << "Input data (format yyyy/mm/dd): ";
		std::cin >> std::get_time(&local, "%Y/%m/%d");
		t = std::mktime(&local);
		auto itf = birthday.find(t);
		if(itf != birthday.end())
			birthday[t] += ", " + name;
		else 
			birthday[t] = name;
	}

	for (auto &[date, firstName] : birthday)
	{
		local = *std::localtime(&date);
		std::string dateTime = std::to_string(local.tm_mon + 1) + "/" + std::to_string(local.tm_mday);

		if (local.tm_year == curDate.tm_year && local.tm_mon == curDate.tm_mon && local.tm_mday == curDate.tm_mday)
			printf("Today is %s birthday: %s\n", dateTime.c_str(), firstName.c_str());
		else if (local.tm_year > curDate.tm_year || (local.tm_year == curDate.tm_year && local.tm_mon >= curDate.tm_mon && local.tm_mday > curDate.tm_mday))
			printf("%s %s\n", dateTime.c_str(), firstName.c_str());
	}
	return 0;
}