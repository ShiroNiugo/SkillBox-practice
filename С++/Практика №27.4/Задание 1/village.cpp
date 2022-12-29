#include <iostream>
#include <vector>
#include <ctime>

class Branch
{
	Branch* parent = nullptr;
	std::vector<Branch*> children;
	std::string home = "None";

public:

	void findElfAndCountNeighbors(std::string name, int& count)
	{
		if (home == name)
			(children.empty()) ? parent->countNeighbors(count) : countNeighbors(count);
		if (!children.empty())
			for (auto br : children)
				br->findElfAndCountNeighbors(name, count);
	}

	void countNeighbors(int& count)
	{
		if (home != "None") 
			count++;
		if (!children.empty()) 
			for (auto ch : children)
				ch->countNeighbors(count);
	}

	void setName(std::string branch = "")
	{
		for (int i = 0; i < (int)children.size(); i++)
		{
			printf((branch == "big" ? "-big branch %i" : "--middle branch %i"), (i + 1));
			std::cout << " input elf name: ";
			std::cin >> children[i]->home;
			children[i]->setName();
		}
	}

	Branch(Branch* inParent, std::string branch = "") : parent(inParent)
	{
		for (int i = 0; i < (branch == "big" ? 3 + rand() % 3 : (branch == "mid" ? 2 + rand() % 2 : 0)); i++)
			children.push_back(new Branch(this, (branch == "big" ? "mid" : "")));
	}
};

int main()
{
	std::srand(std::time(nullptr));
	std::vector<Branch*> trees;
	for (int i = 0; i < 1; i++)
	{
		printf("Tree %i\n", (i + 1));
		trees.push_back(new Branch(nullptr, "big"));
		trees[i]->setName("big");
		std::cout << std::endl;
	}
	while (1)
	{
		std::string name;
		std::cout << "Enter name to find Elf: ";
		std::cin >> name;
		if (name == "exit")
			break;
		int countNeighbors = 0;
		for (auto tr : trees)
			if (countNeighbors == 0)
				tr->findElfAndCountNeighbors(name, countNeighbors);
			else
				break;
		printf("Elf %s have %i neighbors\n", name.c_str(), (countNeighbors == 0 ? 0 : --countNeighbors));
	}
	return 0;
}