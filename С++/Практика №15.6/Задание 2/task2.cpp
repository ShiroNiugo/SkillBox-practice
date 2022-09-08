#include <iostream>
#include <vector>

std::string result(std::vector<int> a, int size, int x) {
  for (int i = 0; i < size; i++)
    for (int j = i; j < size; j++)
      if (a[i] + a[j] == x)
        return std::to_string(a[i]) + " and " + std::to_string(a[j]);
      else if (a[i] + a[j] > x)
        break;
  return "Result not found";
}

int main() {
  std::vector<int> a;
  for (int i = 0; i < 4; i++) {
    int num;
    std::cout << "Input number: ";
    std::cin >> num;
    a.push_back(num);
  }
  int x;
  std::cout << "Input result: ";
  std::cin >> x;
  std::cout << result(a, a.size(), x) << std::endl;
  return 0;
}