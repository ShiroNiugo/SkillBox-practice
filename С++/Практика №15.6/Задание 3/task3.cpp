#include <iostream>
#include <vector>

void sortArrayAndInputElement(std::vector<int> array, int size) {
  if (array.size() < 5)
    std::cerr << "Elements less than 5\n";
  else {
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        if (array[i] < array[j])
          std::swap(array[i], array[j]);
    std::cout << array[4] << std::endl;
  }
}

int main() {
  std::vector<int> array;

  do {
    int num;
    std::cout << "Input number: ";
    std::cin >> num;

    if (num > 0)
      array.push_back(num);
    else if (num == -1)
      sortArrayAndInputElement(array, array.size());
    else if (num == -2)
      break;
  } while (1);
  return 0;
}