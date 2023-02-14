#include <iostream>

int main() {
  unsigned int x {20u};
  int y{30};

  // The output will be 4294967286!
  // This is because the value of y is converted to unsigned int to match the type of x
  std::cout << x - y << std::endl;

  // x -> int
  int test1 = x - y;
  std::cout << test1 << std::endl;

  // y -> unsigned int 
  unsigned test2 = x - y;
  std::cout << test2 << std::endl;

  return 0;
}