#include <iostream>
#include <fstream>
#include <string>

// D:\\test\\statement2.txt

bool validDate(int day, int month, int year)
{
	if (month < 1 || month > 12)
	{
		return false;
	}
	else
	{
		int daysInMonth =
			((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
			  month == 10 || month == 12)
				 ? 31
				 : ((month == 4 || month == 6 || month == 9 || month == 11)
						? 30
						: ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
							   ? 29
							   : 28)));

		return (1 <= day && day <= daysInMonth) ? true : false;
	}
}

int main()
{
	std::string path, firstName, secondName, date;
	int money;

	std::cout << "Input path (\\ -> \\\\): ";
	getline(std::cin, path);
	std::ofstream file(path, std::ios::app);
	if (file.is_open())
	{
		do
		{
			std::cout << "firstName, secondName, date(dd.mm.yyyy), money: ";
			std::cin >> firstName >> secondName >> date >> money;
		} while (!validDate(std::stoi(date.substr(0, 2)), std::stoi(date.substr(3, 2)), std::stoi(date.substr(6, 4))));
		file << "\n\n" << firstName << " " << secondName << " " << date << " " << money << " RUB.\n";
		file.close();
	}

	return 0;
}