#include <iostream>
#include <cstring>

bool substr(char *first, char *second)
{
	int i = 0, j = 0, count = 0;

	while (*(second + i) != '\0')
	{
		if (*(second + i) == *(first + j))
		{
			count++;
			i++;
		}
		if (*(first + j) != '\0')
			j++;
		else
			break;
	}
	return (i == count && count != 0 ? 1 : 0);
}

int main()
{
	char a[] = "Hello world", b[] = "wor", c[] = "banana";

	std::cout << substr(a, b) << " " << substr(a, c) << std::endl;
	return 0;
}