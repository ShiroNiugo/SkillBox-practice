#include <iostream>

#define DAYS(weekday) std::cout << ((weekday == 1) ? "Monday" : (weekday == 2) ? "Tuesday"           \
															: (weekday == 3)   ? "Wednesday"         \
															: (weekday == 4)   ? "Thursday"          \
															: (weekday == 5)   ? "Friday"            \
															: (weekday == 6)   ? "Saturday"          \
															: (weekday == 7)   ? "Sunday"            \
																			   : "Days of the week 7") \
								<< std::endl

int main()
{
	int weekday;
	std::cout << "Input weekday: ";
	std::cin >> weekday;
	DAYS(weekday);
	return 0;
}