#include <iostream>
#include <string>
#include <sstream>

int main()
{
	enum switches
	{
		LIGHTS_INSIDE = 1,
		LIGHTS_OUTSIDE = 2,
		HEATERS = 4,
		WATER_PIPE_HEATING = 8,
		CONDITIONER = 16
	};

	int switches_state = 0, colorTemperature = 5000, tempHour = 0;

	for (int day = 1, hour = 0; day <= 2; (hour < 23 ? hour++ : hour = 0), ((hour < tempHour) ? (day++) : day))
	{
		tempHour = hour;
		int temperatureOutside, temperatureInside;
		std::string data, movements;
		do
		{
			std::cout << "Day - " << day << " hour - " << (((hour <= 9) ? "0" + std::to_string(hour) : std::to_string(hour)) + ":00") << ". Input  temperature outside, temperature inside, movement outside: ";
			getline(std::cin, data);
			std::stringstream info(data);
			info >> temperatureOutside >> temperatureInside >> movements;
		} while (movements != "no" && movements != "yes");
		std::cout << day << " " << hour << " " << temperatureOutside << " " << temperatureInside << " " << movements << std::endl;
		
		if (temperatureOutside < 0 || temperatureOutside < 5)
			switches_state |= WATER_PIPE_HEATING;
		else
			switches_state &= ~WATER_PIPE_HEATING;
		std::cout << "The water pipe heating is " << ((switches_state & WATER_PIPE_HEATING) ? "on\n" : "off\n");
		
		if (movements == "yes" && (hour < 5 || hour > 16))
			switches_state |= LIGHTS_OUTSIDE;
		else
			switches_state &= ~LIGHTS_OUTSIDE;
		std::cout << "The light outside is " << ((switches_state & LIGHTS_OUTSIDE) ? "on\n" : "off\n");
		
		if (temperatureOutside < 22 || temperatureOutside < 25)
			switches_state |= HEATERS;
		else
			switches_state &= ~HEATERS;
		std::cout << "The heaters is " << ((switches_state & HEATERS) ? "on\n" : "off\n");
		
		if (temperatureInside >= 30 || (temperatureInside > 25))
			switches_state |= CONDITIONER;
		else
			switches_state &= ~CONDITIONER;
		std::cout << "The conditioner is " << ((switches_state & CONDITIONER) ? "on\n" : "off\n");
		
		if ((hour <= 20 && hour >= 16))
		{
			switches_state |= LIGHTS_INSIDE;
			colorTemperature -= (hour == 16) ? 0 : 575;
		}
		else
			switches_state &= ~LIGHTS_INSIDE;
		colorTemperature = (hour == 0) ? 5000 : colorTemperature;
		std::cout << "The light inside is " << ((switches_state & LIGHTS_INSIDE) ? "on " : "off ") << colorTemperature << std::endl;
	}

	return 0;
}