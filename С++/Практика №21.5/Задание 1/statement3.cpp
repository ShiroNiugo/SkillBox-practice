#include <iostream>
#include <fstream>
#include <string>

// D:\\test\\statement3.txt

struct formatStr
{
	std::string firstName, 
		  		secondName, 
		  		date,
				currency;
	int money;
};

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
	std::string path, command;

	std::cout << "Input path (\\ -> \\\\): ";
	getline(std::cin, path);

	std::ifstream fileRead(path);

	if (fileRead.is_open())
	{
		formatStr str;
		std::cout << "Input command: ";
		std::cin >> command;

		if (command == "list")
		{
			while (!fileRead.eof())
			{
				fileRead >> str.firstName >> str.secondName >> str.date >> str.money >> str.currency;
				if(str.firstName != "" && !fileRead.eof())
					std::cout << str.firstName << " " << str.secondName << " " << str.date << " " << str.money << " " << str.currency << std::endl;
			}
		}
		else if (command == "add")
		{
			std::ofstream file(path, std::ios::app);
			do
			{
				std::cout << "firstName, secondName, date(dd.mm.yyyy), money: ";
				std::cin >> str.firstName >> str.secondName >> str.date >> str.money;
			} while (!validDate(std::stoi(str.date.substr(0, 2)), std::stoi(str.date.substr(3, 2)), std::stoi(str.date.substr(6, 4))));
			file << "\n" << str.firstName << " " << str.secondName << " " << str.date << " " << str.money << " RUB.\n";
			file.close();
		}
		fileRead.close();
	}

	return 0;
}