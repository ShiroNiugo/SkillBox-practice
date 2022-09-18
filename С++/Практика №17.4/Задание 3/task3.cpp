#include <iostream>
#include <cstring>

bool substr(char *first, char *second)
{
	int i = 0, j = 0, size = strlen(second);

	while (*(second + i) != '\0')
	{
		if (*(second + i) == *(first + j))
			i++;
		if (*(first + j) != '\0')
			j++;
		else
			break;
	}
	return (i == size && i != 0 ? 1 : 0);
}

int main()
{
	char a[] = "Hello world", b[] = "wor", c[] = "banana";

	std::cout << substr(a, b) << " " << substr(a, c) << std::endl;
	return 0;
}