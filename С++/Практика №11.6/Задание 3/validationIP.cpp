#include <iostream>
#include <algorithm>

bool address_part(std::string ip, size_t octet)
{
	size_t pos = 0, pos2 = 0, count = 0;
	for (size_t i = 0; i < ip.size(); i++)
		if ((ip[i] >= '0' && ip[i] <= '9') || ip[i] == '.')
		{
			if (ip[i] == '.' || i == ip.size() - 1)
			{
				pos = (count == 0) ? pos : pos2 + 1;
				pos2 = (count != 3) ? i : ip.size();
				if (octet == count)
				{
					pos2 -= pos;
					if (pos2 == 0) return false;
					ip = ip.substr(pos, pos2);
					std::cout << ip << std::endl;
					if (!(ip.size() > 1 && ip[0] == '0') && (std::count(ip.begin(), ip.end(), '0') <= 1) && stoi(ip) >= 0 && stoi(ip) <= 255) return true;
				}
				count++;
			}
		}
		else
			return false;

	return false;
}

int main()
{
	std::string ip;
	std::cout << "Input IP: ";
	std::cin >> ip;
	std::cout << "Result: " << (ip.front() != '.' && ip.back() != '.' && (address_part(ip, 0) && address_part(ip, 1) && address_part(ip, 2) && address_part(ip, 3)) ? "valid" : "invalid") << std::endl;
	return 0;
}