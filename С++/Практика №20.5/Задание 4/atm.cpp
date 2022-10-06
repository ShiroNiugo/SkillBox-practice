#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

// D:\\test\\atmBill.txt

int main()
{
	std::string path, str;
	int bill[] = {100, 500, 1000, 2000, 5000}, sumMoney;
	std::vector<int> atm;

	std::srand(std::time(nullptr));

	std::cout << "Input path (\\ -> \\\\): ";
	getline(std::cin, path);
	std::ifstream file(path);
	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> str;
			atm.push_back(stoi(str));
		}
		file.close();
		char symbol;
		do
		{
			std::cout << "Input (+/-): ";
			std::cin >> symbol;
		} while (symbol != '+' && symbol != '-');
		if (symbol == '+')
		{
			std::ofstream add(path, std::ios::app);
			for (size_t i = (!atm.empty() ? atm.size() : 1); i < 1000; i++)
				(i != 1) ? (add << std::endl << bill[std::rand() % 5]) : (add << bill[std::rand() % 5]);
			add.close();
		}
		else
		{
			std::cout << "Input amount of money: ";
			std::cin >> sumMoney;
			std::ofstream rewrite(path);
			for (size_t i = 0; i < atm.size(); i++)
				if (sumMoney >= 100)
				{
					if (sumMoney >= atm[i])
					{
						sumMoney -= atm[i];
						atm[i] = 0;
					}
				}
				else
				{
					(i != atm.size() - 1) ? (rewrite << atm[i] << std::endl) : (rewrite << atm[i]);
				}
			rewrite.close();
			if (sumMoney != 0)
				printf("Impossible to withdraw %i\n:", sumMoney);
		}
	}
	return 0;
}