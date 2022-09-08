#include <iostream>
#include <vector>

void sortArrayAndInputElements(std::vector<int> array, int size) {
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      if (abs(array[i]) < abs(array[j]))
        std::swap(array[i], array[j]);
  for (int i = 0; i < size; i++)
    std::cout << array[i] << " ";
  std::cout << std::endl;
}

int main() {
  std::vector<int> array;
  for (int i = 0; i < 6; i++) {
    int num;
    std::cout << "Input number: ";
    std::cin >> num;
    array.push_back(num);
  }
  sortArrayAndInputElements(array, array.size());
  return 0;
}