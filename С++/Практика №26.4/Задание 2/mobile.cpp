#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

bool isNumber(std::string s) {
  return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

class PhoneBook {
public:
  std::map<std::string, std::string> book;
};

class Mobile {
  PhoneBook *book = new PhoneBook();

public:
  void add() {
    std::string name, number;
    do {
      printf("Input number: +7");
      std::cin >> number;
    } while (isNumber(number) && number.length() != 10);
    printf("Input name: ");
    std::cin >> name;
    book->book[number] = name;
    printf("Contact add!\n");
  }
  std::string getNickname(std::string digit) {
    return book->book.find(digit)->second;
  }
  std::vector<std::string> getNumber(std::string nickname) {
    std::vector<std::string> temp;
    for (auto &[number, name] : book->book)
      if (name == nickname)
        temp.push_back(number);
    return temp;
  }
};

void callOrSms(Mobile *phone, std::string command) {
  std::string numOrName, nickname;
  std::vector<std::string> number;
  do {
    std::cout << "Input name or number(+7...): ";
    std::cin >> numOrName;
  } while (phone->getNickname(numOrName).empty() &&
           phone->getNumber(numOrName).empty());
  if (isNumber(numOrName))
    nickname = phone->getNickname(numOrName);
  else
    number = phone->getNumber(numOrName);
  int digit = 0;
  if (number.size() > 1) {
    for (size_t i = 0; i < number.size(); i++)
      printf("%i: %s +7%s\n", (int)(i + 1), numOrName.c_str(),
             number[i].c_str());
    do {
      std::cout << "Input contact digit: ";
      std::cin >> digit;
    } while (digit > (int)number.size() || digit <= 0);
  }
  if (command == "sms") {
    command += " sent";
    std::string message;
    std::cout << "Input message: ";
    std::cin.ignore();
    std::getline(std::cin, message);
  }
  printf("%s %s +7%s\n", command.c_str(),
         (nickname.empty() ? numOrName.c_str() : nickname.c_str()),
         (number.empty()
              ? numOrName.c_str()
              : number[number.size() > 1 ? (digit - 1) : 0].c_str()));
}

int main() {
  Mobile *phone = new Mobile;
  std::string command;
  do {
    std::cout << "Input command: ";
    std::cin >> command;
    if (command == "add")
      phone->add();
    else if (command == "call")
      callOrSms(phone, command);
    else if (command == "sms")
      callOrSms(phone, command);
  } while (command != "exit");
  delete phone;
  return 0;
}