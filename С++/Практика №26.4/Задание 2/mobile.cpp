#include <iostream>
#include <vector>
#include <algorithm>

class PhoneBook
{
	public:
		std::string number, name;
};

class Mobile{
	public:
	std::vector<PhoneBook> book;
		void add(std::string name, std::string number)
		{
			PhoneBook *addBook = new PhoneBook{number, name};
			book.push_back(*addBook);
			delete addBook;
		}
		std::vector<PhoneBook> getNickname(std::string digit)
		{
			std::vector<PhoneBook> temp;
			for(auto &[number, name] : book)
				if(number == digit){
					PhoneBook *addBook = new PhoneBook{number, name};
					temp.push_back(*addBook);
					delete addBook;
				}
			return temp;
		}
		std::vector<PhoneBook> getNumber(std::string nickname)
		{
			std::vector<PhoneBook> temp;
			for(auto &[number, name] : book)
				if(name == nickname){
					PhoneBook *addBook = new PhoneBook{number, name};
					temp.push_back(*addBook);
					delete addBook;
				}
			return temp;
		}
};

bool isNumber(std::string s){
	return !s.empty() && std::find_if(s.begin(), s.end(),[](unsigned char c){return !std::isdigit(c);}) == s.end();
}

void callOrSms(Mobile *phone, std::string command){
	std::string call;
	std::cout << "Input name or number(+7...): ";
	std::cin >> call;
	std::vector<PhoneBook> book;
	if(isNumber(call)) book = phone->getNickname(call);
	else book = phone->getNumber(call);
	if(book.size() > 1){
		for(size_t i = 0; i < book.size(); i++)
			printf("%i %s +7%s\n", ((int)i+1), book[i].name.c_str(), book[i].number.c_str());
		int digit;
		std::string message;
		std::cout << "Input contact digit: ";
		std::cin >> digit;
		if(command == "sms"){
			std::cout << "Input message: ";
			getline(std::cin, message);
		}
		printf("%s %s +7%s\n", command.c_str(), book[digit-1].name.c_str(), book[digit-1].number.c_str());
	}else 
		printf("%s %s +7%s\n", command.c_str(), book.begin()->name.c_str(), book.begin()->number.c_str());
}

int main()
{
	Mobile *phone = new Mobile;
	std::string command;
	do{
		std::cout << "Input command: ";
		std::cin >> command;
		if (command == "add")
		{
			std::string name, number;
			do{
				printf("Input number: +7");
				std::cin >> number;
			} while(isNumber(number) && number.length() != 10);
			printf("Input name: ");
			std::cin >> name;
			phone->add(name, number);
		}
		else if (command == "call"){
			callOrSms(phone, command);
		}else if(command == "sms"){
			callOrSms(phone, command);
			std::cout << std::endl;
		}
	} while (command != "exit");
	delete phone;
	return 0;
}