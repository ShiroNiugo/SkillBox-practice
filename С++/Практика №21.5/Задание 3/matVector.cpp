#include <iostream>
#include <vector>
#include <math.h>

struct matVector
{
	float digit;
	std::vector<std::vector<float>> vec;
};

std::string add(matVector vec)
{
	for (int i = 0; i < 3; i++)
	{
		vec.vec.resize(vec.vec.size() + 1);
		if (i != 2)
		{
			for (int j = 0; j < 2; j++)
			{
				printf("%s%i = ", (j == 0 ? "x" : "y"), (i + 1));
				std::cin >> vec.digit;
				vec.vec[i].push_back(vec.digit);
			}
		}
		else
			for (int j = 0; j < 2; j++)
				vec.vec[i].push_back(vec.vec[i - 2][j] + vec.vec[i - 1][j]);
	}
	return "(" + std::to_string(vec.vec[2][0]) + ";" + std::to_string(vec.vec[2][1]) + ")";
}

std::string subtract(matVector vec)
{
	for (int i = 0; i < 3; i++)
	{
		vec.vec.resize(vec.vec.size() + 1);
		if (i != 2)
		{
			for (int j = 0; j < 2; j++)
			{
				printf("%s%i = ", (j == 0 ? "x" : "y"), (i + 1));
				std::cin >> vec.digit;
				vec.vec[i].push_back(vec.digit);
			}
		}
		else
			for (int j = 0; j < 2; j++)
				vec.vec[i].push_back(vec.vec[i - 2][j] - vec.vec[i - 1][j]);
	}
	return "(" + std::to_string(vec.vec[2][0]) + ";" + std::to_string(vec.vec[2][1]) + ")";
}

std::string scale(matVector vec, float scale = 0)
{
	std::cout << "Scalar: ";
	std::cin >> scale;
	vec.vec.resize(vec.vec.size() + 1);
	for (int j = 0; j < 2; j++)
	{
		printf("%s%i = ", (j == 0 ? "x" : "y"), (1));
		std::cin >> vec.digit;
		vec.vec[0].push_back(vec.digit * scale);
	}
	return "(" + std::to_string(vec.vec[0][0]) + ";" + std::to_string(vec.vec[0][1]) + ")";
}

float length(matVector vec)
{
	vec.vec.resize(vec.vec.size() + 1);
	for (int j = 0; j < 2; j++)
	{
		printf("%s = ", (j == 0 ? "x" : "y"));
		std::cin >> vec.digit;
		vec.vec[0].push_back(vec.digit);
	}
	return sqrt(pow(vec.vec[0][0], 2) + pow(vec.vec[0][1], 2));
}

float normalize(matVector vec)
{
	vec.vec.resize(vec.vec.size() + 1);
	for (int j = 0; j < 2; j++)
	{
		printf("%s = ", (j == 0 ? "x" : "y"));
		std::cin >> vec.digit;
		vec.vec[0].push_back(vec.digit);
	}
	float lengthVec = sqrt(pow(vec.vec[0][0], 2) + pow(vec.vec[0][1], 2));
	return (pow(vec.vec[0][0]/lengthVec, 2) + pow(vec.vec[0][1]/lengthVec, 2));
}

int main()
{
	matVector vec;
	std::string operation;
	std::cout << "Input operations (add, subtract, scale, length, normalize): ";
	std::cin >> operation;
	if (operation == "add")
		printf("Add %s\n", add(vec).c_str());
	else if (operation == "subtract")
		printf("Subtract %s\n", subtract(vec).c_str());
	else if (operation == "scale")
		printf("Scale %s\n", scale(vec).c_str());
	else if (operation == "length")
		printf("Length %s\n", std::to_string(length(vec)).c_str());
	else if (operation == "normalize")
		printf("Normalize %s\n", std::to_string(normalize(vec)).c_str());
	return 0;
}