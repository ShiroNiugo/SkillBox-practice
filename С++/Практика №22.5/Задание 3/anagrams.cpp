#include <iostream>
#include <string>
#include <map>

bool check(std::map<char, int> firstWord, std::string secondWord)
{
	if (firstWord.size() != secondWord.length())
		return false;
	for (auto ch : secondWord)
		if (firstWord.find(ch)->second != 0)
			if (firstWord.find(ch)->second == 1)
				firstWord.erase(ch);
			else
				firstWord[ch]--;
		else
			return false;
	return true;
}

int main()
{
	std::map<char, int> anagram;
	std::string word;
	for (int i = 0; i < 2; i++)
	{
		printf("Input %s: ", (i == 0 ? "first" : "second"));
		std::cin >> word;
		if (i == 0)
			for (auto ch : word)
				anagram[ch]++;
	}
	std::cout << (check(anagram, word) ? "The words are an anagram" : "Words are not an anagram") << std::endl;
	return 0;
}