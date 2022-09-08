#include <iostream>
#include <vector>

std::string result(std::vector<int> a, int size) {
  int max = 0, x, y;
  for (int i = 0; i < size; i++) {
    int current = 0;
    for (int j = i; j < size; j++) {
      current += a[j];
      if (current > max) {
        max = current;
        x = i;
        y = j;
      }
    }
  }
  return std::to_string(x) + " " + std::to_string(y) +
         " sum = " + std::to_string(max);
}

int main() {
  std::vector<int> a;
  for (int i = 0; i < 9; i++) {
    int num;
    std::cout << "Input number: ";
    std::cin >> num;
    a.push_back(num);
  }
  std::cout << result(a, a.size()) << std::endl;
  return 0;
}