#include <iostream>

class Toy {
	std::string name;
public:
	Toy(std::string inName) : name(inName) {}
	Toy() : Toy("Unknown") {}
	std::string getName() {
		return name;
	}
};

class Shared_ptr_toy {
	Toy* obj;
	int* count;
public:
	void addCountLink() {
		if (count != nullptr) *count+=1;
	}
	void subtractCountLink() {
		if (count != nullptr) *count-=1;
	}
	int getCountLink() {
		return *count;
	}

	Shared_ptr_toy(Toy* oth) : obj(oth), count((nullptr == obj) ? new int(0) : new int(1)) {}
	Shared_ptr_toy(const Shared_ptr_toy& oth) : obj(oth.obj), count(oth.count) { addCountLink(); }
	Shared_ptr_toy() : Shared_ptr_toy(nullptr) {}

	Shared_ptr_toy& operator=(const Shared_ptr_toy& oth) {
		if (this == &oth)
			return *this;
		subtractCountLink();
		if (getCountLink() == 0) {
			delete obj;
			delete count;
		}
		obj = oth.obj;
		count = oth.count;
		addCountLink();
		return *this;
	}
	Toy* operator->() { return obj; }

	~Shared_ptr_toy() {
		subtractCountLink();
		if (getCountLink() == 0) {
			delete obj;
			delete count;
		}
	}
};

Shared_ptr_toy make_shared_toy(const std::string& name) {
	return Shared_ptr_toy(new Toy(name));
}
Shared_ptr_toy make_shared_toy(const Toy& toy) {
	return Shared_ptr_toy(new Toy(toy));
}

int main() {
	Toy t("Ball");
	Shared_ptr_toy a = make_shared_toy(t);
	Shared_ptr_toy b = make_shared_toy("Doll");
	std::cout << a->getName() << " = " << a.getCountLink() << ", " << b->getName() << " = " << b.getCountLink() << std::endl << std::endl;
	Shared_ptr_toy c(a);
	std::cout << a->getName() << " = " << a.getCountLink() << ", " << b->getName() << " = " << b.getCountLink() << std::endl << std::endl;
	Shared_ptr_toy d = a;
	std::cout << a->getName() << " = " << a.getCountLink() << ", " << b->getName() << " = " << b.getCountLink() << std::endl << std::endl;
	d = b;
	std::cout << a->getName() << " = " << a.getCountLink() << ", " << b->getName() << " = " << b.getCountLink() << std::endl << std::endl;
}