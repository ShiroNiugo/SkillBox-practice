#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::vector<std::string> grid;
std::mutex gridAccess;

void timer(int player, float speed)
{
	for (float start = speed; start <= 100; start += speed)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		printf("swimmer %i = %f\n", player, start);
	}
	gridAccess.lock();
	grid.push_back("Swimmer " + std::to_string(player));
	gridAccess.unlock();
}

int main()
{
	float speed;
	std::vector<float> swimmerSpeed;
	for (int i = 0; i < 6; i++)
	{
		do
		{
			printf("Input swimmer %i: ", (i + 1));
			std::cin >> speed;
		} while (speed <= 0);
		swimmerSpeed.push_back(speed);
	}

	std::thread swimmer1(timer, 1, swimmerSpeed[0]);
	std::thread swimmer2(timer, 2, swimmerSpeed[1]);
	std::thread swimmer3(timer, 3, swimmerSpeed[2]);
	std::thread swimmer4(timer, 4, swimmerSpeed[3]);
	std::thread swimmer5(timer, 5, swimmerSpeed[4]);
	std::thread swimmer6(timer, 6, swimmerSpeed[5]);
	swimmer1.join();
	swimmer2.join();
	swimmer3.join();
	swimmer4.join();
	swimmer5.join();
	swimmer6.join();

	gridAccess.lock();
	printf("\nFinal grid:\n");
	for (int i = 0; i < (int)grid.size(); i++)
		printf("%i %s\n", (i+1), grid[i].c_str());
	gridAccess.unlock();

	return 0;
}