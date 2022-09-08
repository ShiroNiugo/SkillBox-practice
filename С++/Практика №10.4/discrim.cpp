#include <iostream>
#include <cmath>
int main()
{
  float a, b, c;
  std::cout << "a, b, c:";
  std::cin >> a >> b >> c;
  if (a == 0)
  {
    std::cout << "Not a quadratic equation!" << std::endl;
  }
  else if (b == 0 && c == 0)
  {
    std::cout << "Root: 0" << std::endl;
  }
  else if (b == 0)
  {
    if (-(c / a) < 0)
    {
      std::cout << "There are no roots" << std::endl;
    }
    else
    {
      float x1 = std::sqrt(-(c / a));
      float x2 = -std::sqrt(-(c / a));
      std::cout << "Root 1, 2: " << x1 << ", " << x2 << std::endl;
    }
  }
  else if (c == 0)
  {
    std::cout << "Root 1, 2: " << 0 << ", " << (-(b/a)) << std::endl;
  }
  else
  {
    float discriminant = b * b - 4 * a * c;
    if (discriminant > 1)
    {
      float x1 = (-b + std::sqrt(discriminant)) / (2 * a);
      float x2 = (-b - std::sqrt(discriminant)) / (2 * a);
      std::cout << "Root 1, 2: " << x1 << ", " << x2 << std::endl;
    }
    else if (discriminant == 0)
    {
      float x = -b / (2 * a);
      std::cout << "Root: " << x << std::endl;
    }
    else
    {
      std::cout << "Complex scenario is not supported!" << std::endl;
    }
  }
  return 0;
}