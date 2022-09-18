#include <iostream>

int main()
{
	float speedValue = 0;
	char speed_str[100];
	do
	{
		float delta;
		std::cout << "Input delta: ";
		std::cin >> delta;
		std::sprintf(speed_str, "%.01f", delta);
		delta = std::stof(speed_str);

		speedValue = (speedValue + delta <= 0) ? 0 : ((speedValue + delta >= 150) ? 150 : (speedValue + delta));
		std::sprintf(speed_str, "%.1f", speedValue);
		std::cout << speed_str << " km/h" << std::endl;
		speedValue = std::stof(speed_str);
	} while (speedValue > 0);
	return 0;
}