#include <iostream>
#include <vector>

struct room
{
	float square;
	int roomType;
	enum room_type
	{
		bedroom = 1,
		kitchen = 2,
		bathroom = 4,
		children = 8,
		living = 16
	};
};

struct floor
{
	float height;
	std::vector<room> rooms;
};

struct house
{
	float square;
	int facilityType;
	std::vector<floor> floors;
	enum facility_type
	{
		livingHouse = 1,
		garage = 2,
		shed = 4,
		sauna = 8
	};
	bool oven = false;
};

struct area
{
	int number;
	std::vector<house> home;
};

int main()
{
	int plots;
	do
	{
		std::cout << "Enter the number of plots: ";
		std::cin >> plots;
	} while (plots <= 0);
	std::vector<area> village;
	for (int i = 0; i < plots; i++)
	{
		area plot;
		plot.number = i + 1;
		int building;
		do
		{
			printf("Enter the number of residential buildings on the plot N%i: ", plot.number);
			std::cin >> building;
		} while (building < 0);
		for (int j = 0; j < building; j++)
		{
			house home;
			int floors, number, state = 0;
			do
			{
				printf("Enter the square of building %i: ", (j + 1));
				std::cin >> home.square;
			} while (home.square < 0);
			float square = home.square;
			if (j == 0)
			{
				printf("Living house\n");
				state |= home.livingHouse;
				home.facilityType = state;
				home.oven = true;
				do
				{
					printf("Enter the number of floors: ");
					std::cin >> floors;
				} while (floors < 0 || floors > 4);
				for (int k = 0; k < floors; k++)
				{
					floor level;
					int rooms;
					do
					{
						printf("Input floor %i height: ", (k + 1));
						std::cin >> level.height;
					} while (level.height < 0);
					do
					{
						printf("Enter the number of rooms per floor N%i: ", (k + 1));
						std::cin >> rooms;
					} while (rooms < 2 || rooms > 5);
					for (int l = 0; l < rooms; l++)
					{
						room apartment;
						state = 0;
						do
						{
							printf("Input room %i square (%f): ", (l + 1), square);
							std::cin >> apartment.square;
						} while (apartment.square < 0 || (square-apartment.square) < 0);
						square-=apartment.square;
						do
						{
							printf("Enter the room type N%i (1 - bedroom, 2 - kitchen, 3 - bathroom, 4 - children's room, 5 - living room): ", (l + 1));
							std::cin >> number;
						} while (number < 0 || number > 6);
						state |= (number == 1)	 ? apartment.bedroom
								 : (number == 2) ? apartment.kitchen
								 : (number == 3) ? apartment.bathroom
								 : (number == 4) ? apartment.children
												 : apartment.living;

						apartment.roomType = state;
						level.rooms.push_back(apartment);
					}
					home.floors.push_back(level);
				}
			}
			else
			{
				do
				{
					printf("Enter the type of additional buildings N%i (1 - garage, 2 - shed, 3 - sauna): ", (j + 1));
					std::cin >> number;
				} while (number <= 0 || number > 4);
				if (number == 1)
				{
					state |= home.garage;
					home.facilityType = state;
				}
				else if (number == 2)
				{
					state |= home.shed;
					home.facilityType = state;
				}
				else if (number == 3)
				{
					state |= home.sauna;
					home.facilityType = state;
					home.oven = true;
				}
			}
			plot.home.push_back(home);
		}
		village.push_back(plot);
	}

	std::cout << "\nResult\n\n";

	float sumSquare = 0;
	for (auto v : village)
	{
		printf("Area N%i\n", v.number);
		for (auto h : v.home)
		{
			int state = h.facilityType;
			std::cout << "- ";
			if (state & h.livingHouse)
			{
				printf("Living, square = %f, oven %s\n", h.square, (h.oven ? "true" : ""));
				int i = 0;
				for (auto f : h.floors)
				{
					std::cout << "\t";
					printf("Floor %i, height = %f\n", ++i, f.height);
					for (auto r : f.rooms)
					{
						std::cout << "\t- ";
						state = r.roomType;
						printf((state & r.bedroom) ? "Bedroom, square = %f\n"
												   : ((state & r.kitchen) ? "Kitchen, square = %f\n"
																		  : ((state & r.bathroom) ? "Bathroom, square = %f\n"
																								  : ((state & r.children) ? "Children, square = %f\n"
																														  : "Living, square = %f\n"))),
							   r.square);
					}
				}
			}
			else if (state & h.garage)
				printf("Garage = %f\n", h.square);
			else if (state & h.shed)
				printf("Shed = %f\n", h.square);
			else if (state & h.sauna)
				printf("Sauna = %f, oven %s\n", h.square, (h.oven ? "true" : ""));
			sumSquare += h.square;
		}
	}
	printf("Total number of square meters in the village: %f\n", sumSquare);

	return 0;
}