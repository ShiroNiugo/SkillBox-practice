#include <iostream>
#include <vector>
#include <ctime>

class Employee
{
public:
	std::string name;
	char task;
	bool busy = false;
	Employee(std::string inName, int number) : name(inName + (number != 0 ? " " + std::to_string(number) : "")) {}
};

class Team
{
	Team *parent = nullptr;
	Employee *worker;
	std::vector<Team *> workers;

public:

	int getTeamWorkers(int count = 0)
	{
		for(auto w : workers){
			if(w->workers.empty())
				count += (!w->worker->busy ? 1 : 0);
			if(!w->workers.empty())
				count += w->getTeamWorkers();
		}
		return count;
	}

	void setTask(int &countTask){
		char typeTask[3]{'A','B','C'};
		for(auto w : workers){
			if(countTask == 0) break;
			if(!w->workers.empty()){
				printf("\"%s\" took the task\n", w->worker->name.c_str());
				w->setTask(countTask);
			}
			else{
				if(!w->worker->busy){
					w->worker->busy = true;
					w->worker->task = typeTask[rand() % 3];
					printf("Worker \"%s\" was given a type %c task\n", w->worker->name.c_str(), w->worker->task);
					countTask--;
				}
			}
		}
	}

	Team(Team *inParent, int countTeam, int countWorkers, std::string name = "Director", int numberTeam = 0) : parent(inParent)
	{
		worker = new Employee(name, numberTeam);
		if (name != "Employee")
			for (int i = 0; i < countTeam; i++)
				workers.push_back(new Team(this, countWorkers, 0, (name == "Manager") ? "Employee" : "Manager", (i + 1)));
	}
};

int main()
{
	int countTeam, countWorkers, hash;
	std::cout << "Input count teams and workers: ";
	std::cin >> countTeam >> countWorkers;
	Team *company = new Team(nullptr, countTeam, countWorkers);
	do{
		std::cout << "Free workers: " << company->getTeamWorkers() << std::endl;
		std::cout << "Input integer digit: ";
		std::cin >> hash;
		std::srand(hash);
		int taskCount = rand() % (company->getTeamWorkers() + 1);
		company->setTask(taskCount);
	}while(company->getTeamWorkers() != 0);
	delete company;
	return 0;
}