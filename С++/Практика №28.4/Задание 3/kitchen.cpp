#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <ctime>

int countDelivery = 0;
std::vector<std::string> orders, temp;
std::mutex ordersAccess;

void accept(std::string dish, int index)
{
	std::this_thread::sleep_for(std::chrono::seconds(5 + rand() % 11));
	printf("Ready %s order %i\n", dish.c_str(), index);
	temp.push_back("Order " + std::to_string(index)+ ": "+ dish +" delivered");
	ordersAccess.lock();
	if (orders.empty()){
		orders = temp;
		temp.clear();
	}
	if (!orders.empty())
	{
		std::this_thread::sleep_for(std::chrono::seconds(30));
		printf("Successful delivery %i:\n", (countDelivery+1));
		for (auto o : orders)
			printf("%s\n", o.c_str());
		countDelivery++;
		orders.clear();
	}
	ordersAccess.unlock();
}

void order(std::string dish, int index)
{
	std::this_thread::sleep_for(std::chrono::seconds(5 + rand() % 6));
	printf("Order %i: %s\n", index, dish.c_str());
	std::thread acceptDish(accept, dish, index);
	acceptDish.detach();
}

int main()
{
	srand(std::time(nullptr));
	std::string dishes[5]{"pizza", "soup", "steak", "salad", "sushi"};
	int index = 1;
	while(1)
	{
		if (countDelivery == 10)
			break;
		else{
			std::thread dish(order, dishes[rand() % 5], index);
			dish.join(); 
			index++;
		}
	}

	return 0;
}