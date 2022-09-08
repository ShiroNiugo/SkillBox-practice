#include <iostream>

void masAdd(int arr[][4])
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			std::cin >> arr[i][j];
}

int main()
{
	int A[4][4], B[4][4];
	bool equel = true;

	std::cout << "Matrix A: ";
	masAdd(A);

	std::cout << "Matrix B: ";
	masAdd(B);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (A[i][j] != B[i][j])
			{
				equel = !equel;
				break; 
			}
			if (i != j)
				A[i][j] = 0;
		}

	if (equel)
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				std::cout << A[i][j] << " ";
			std::cout << std::endl;
		}

	std::cout << (equel ? "Equal" : "Not equal") << std::endl;
}