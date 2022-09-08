#include <iostream>

bool compare(float speed_value, float border_speed, float delta)
{
	return (speed_value <= border_speed + delta) && (speed_value >= border_speed - delta);
}

int main()
{
	float speed_value = 0, delta = 0.01f;
	char speed_str[100];
	do{
		std::cout << "Input delta: ";
		std::cin >> speed_value;
		if(compare(speed_value, 150, delta)) continue;
		std::sprintf(speed_str, "%.1f", speed_value);
		std::cout << speed_str << std::endl;
	} while (!compare(speed_value, 0, delta));
	return 0;
}