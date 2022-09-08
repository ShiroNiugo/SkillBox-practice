#include <iostream>
#include <algorithm>

bool checking(std::string part, bool partSecond = true)
{
	std::string allowed = "!#$%&'*+/=?^_`{|}~";
	if (part.front() != '.' && part.back() != '.' && (!partSecond ? (part.size() > 0 && part.size() <= 64) : (part.size() > 0 && part.size() <= 63)))
	{
		for (size_t index = 0; index < part.size(); index++)
		{
			char ch = part[index];
			bool symbol = ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '-' || ch == '.');

			if ((!symbol && !partSecond && std::count(allowed.begin(), allowed.end(), ch) == 0) || (!symbol && partSecond && std::count(allowed.begin(), allowed.end(), ch) == 1) || (part[index - 1] == '.' && ch == '.'))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

int main()
{
	std::string email;
	std::cout << "Input email: ";
	std::cin >> email;
	int pos = email.find('@');
	if (std::count(email.begin(), email.end(), '@') != 1)
	{
		std::cout << "Result: invalid addresses" << std::endl;
		return 0;
	}
	std::string firstPart = email.substr(0, pos),
				secondPart = email.substr(pos + 1, email.size());
	std::cout << "Result: " << ((checking(firstPart, false) && checking(secondPart)) ? "correct addresses" : "invalid addresses") << std::endl;
	return 0;
}