#include <iostream>

int countResult(int n, int k = 3)
{
	/*
	k = 3(default)
	0 - 0  - 0
	1 - 1  - 1
	2 - 2  - 2; 11
	3 - 4  - 3; 21; 12; 1111
	4 - 7  - 31; 13; 22; 211; 121; 112; 1111
	5 - 13 - 32; 23; 311; 131; 113; 221; 212; 122; 2111; 1211; 1121; 1112; 11111
	6 - 24 - 33; 321; 312; 231; 213; 123; 132; 222; 3111; 1311; 1131; 1113; 2211;
			 2121; 1221; 2112; 1122; 1212; 21111; 12111; 11211; 11121; 11112; 111111
	*/
	if (n == 0 || n == 1)
		return 1;
	else if (n == 2)
		return 2;
	return ((k >= 1) ? countResult(n - 1) : 0) + ((k >= 2) ? countResult(n - 2) : 0) + ((k >= 3) ? countResult(n - 3) : 0);
}

int main()
{
	float n, k;
	std::cout << "Input (n, k): ";
	std::cin >> n;
	k=n;
	n=(int)n;
	k-=n;
	std::cout << "Output: " << (k*10!=0?countResult(n, k*10):countResult(n)) << std::endl;
	return 0;
}