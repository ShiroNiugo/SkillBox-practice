#include <iostream>
#include <vector>

int main()
{
	float A[4][4];
	std::vector<float> B(4);
	std::vector<std::vector<float>> C(4);

	std::cout << "Matrix A: ";
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			std::cin >> A[i][j];

	std::cout << "Vector B: ";
	for (int i = 0; i < 4; i++)
		std::cin >> B[i];

	std::cout << "Vector C: " << std::endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++){
			C[i].push_back(A[i][j] * B[j]);
			std::cout << C[i][j] << " ";
		}
		std::cout << std::endl;
	}
}