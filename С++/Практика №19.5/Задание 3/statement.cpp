#include <iostream>
#include <fstream>

// D:\\test\\statement.txt

int main()
{
	std::string path, firstName, lastName, person, date;
	int money, sumMoney = 0, maxMoney;
	std::cout << "Input path (\\->\\\\): ";
	std::cin >> path;
	std::ifstream data(path);
	if (data.is_open())
	{
		while (!data.eof())
		{
			data >> firstName >> lastName >> money >> date;
			if (maxMoney < money)
			{
				person = (firstName + " " + lastName);
				maxMoney = money;
			}
			sumMoney += money;
		}
		std::cout << "Summa money: " << sumMoney
				  << "\nMaximum amount of payments: " << person << std::endl;
		data.close();
	}
	return 0;
}