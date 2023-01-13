#include <iostream>
#include <vector>

class Talent
{
protected:
	std::vector<std::string> talents{"", "", ""};
public:
	virtual void setDance() = 0;
	virtual void setSwim() = 0;
	virtual void setCount() = 0;
};

class Dancing : virtual public Talent{
public:
	void setDance() override
	{
		talents[0] = "\tIt can \"Dance\"\n";
	}
};

class Swimming : virtual public Talent{
public:
	void setSwim() override
	{
		talents[1] = "\tIt can \"Swim\"\n";
	}
};

class Counting : virtual public Talent{
public:
	void setCount() override
	{
		talents[2] = "\tIt can \"Count\"\n";
	}
};

class Animal : virtual public Dancing, virtual public Swimming, virtual public Counting
{
protected:
	std::string name = "Unknown";

public:
	virtual void voice() = 0;
};


class Dog : public Animal
{
public:
	void voice() override
	{
		printf("Bark!\n");
	}
	void showTalents()
	{
		printf("This is %s and it has some talents: \n%s", name.c_str(), (talents[0] == "" && talents[1] == "" && talents[2] == "" ? "\tNo talents\n" : ""));
		for(auto t : talents)
			printf("%s", t.c_str());
	}
	Dog(std::string inName)
	{
		name = inName;
	}
};

int main()
{
	Dog dog1("Steve");
	dog1.voice();
	dog1.showTalents();
	dog1.setCount();
	dog1.setDance();
	dog1.showTalents();
	return 0;
}