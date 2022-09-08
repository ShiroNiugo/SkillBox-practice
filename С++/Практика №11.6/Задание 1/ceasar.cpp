#include <iostream>

std::string encrypt_caesar(std::string str, int offset)
{
	int symbol;
	bool lower = true;
	for (size_t ch = 0; ch < str.size(); ch++)
	{
		str[ch] = (str[ch] - 'a' >= 0 && str[ch] - 'a' < 26)
			? (symbol = (str[ch] - 'a'),
			   lower = true),
		(symbol + offset) % 26 + (lower ? 'a' : 'A')
			: (str[ch] - 'A' >= 0 && str[ch] - 'A' < 26)
			? (symbol = (str[ch] - 'A'),
			   lower = false),
		(symbol + offset) % 26 + (lower ? 'a' : 'A')
			: str[ch];
	}
	return str;
}

std::string decrypt_caesar(std::string str, int offset)
{
	int symbol;
	bool lower = true;
	for (size_t ch = 0; ch < str.size(); ch++)
	{
		str[ch] = (str[ch] - 'a' >= 0 && str[ch] - 'a' < 26)
			? (symbol = (str[ch] - 'a'),
			   lower = true),
		((abs((symbol - offset > 0) ? symbol - offset : 26 + (symbol - offset)) % 26)) + (lower ? 'a' : 'A')
			: (str[ch] - 'A' >= 0 && str[ch] - 'A' < 26)
			? (symbol = (str[ch] - 'A'),
			   lower = false),
		((abs((symbol - offset > 0) ? symbol - offset : 26 + (symbol - offset)) % 26)) + (lower ? 'a' : 'A')
			: str[ch];
	}
	return str;
}

int main()
{
	int offset;
	std::string str;
	std::cout << "Input string: " << std::endl;
	std::getline(std::cin, str);
	do
	{
		std::cout << "Input offset: ";
		std::cin >> offset;
	} while (offset < -26 || offset > 26);
	str = encrypt_caesar(str, (offset < 0 ? 26 + offset : offset));
	std::cout << "Output encrypt string:\n"
			  << str << std::endl;
	str = decrypt_caesar(str, (offset < 0 ? 26 + offset : offset));
	std::cout << "Output decrypt string:\n"
			  << str << std::endl;
	return 0;
}