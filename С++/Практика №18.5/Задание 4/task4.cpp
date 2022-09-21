#include <iostream>

void evendigits(long long digit, int &count)
{
	int remains = digit % 10;
	digit /= 10;
	if (digit != 0)
	{
		if (remains % 2 == 0)
			count++;
		evendigits(digit, count);
	}
}

int main()
{
	int ans;
	evendigits(9223372036854775806, ans);
	std::cout << "even digits: " << ans << std::endl;
	return 0;
}