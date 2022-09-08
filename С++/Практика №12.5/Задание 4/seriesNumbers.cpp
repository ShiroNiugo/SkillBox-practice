#include <iostream>

using namespace std;

int main()
{
	int x, sum = 0, sum2 = 0, minNumber = 105;
	int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
	do
	{
		cout << "Input X: ";
		cin >> x;
	} while (x <= 0 || x > 15);
	x--;
	for (int i = x, j = 0; j < 15; (i < 14 ? (i++) : i = 0), j++, minNumber++)
	{
		sum += (j < 14) ? minNumber : 0;
		sum2 += numbers[i];
	}
	cout << "In this example, X is " << numbers[x]
		 << " and the repeating number is " << (sum2 - sum)
		 << "." << endl;
	return 0;
}