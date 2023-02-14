#include <iostream>

int main() {
  double a {1.5};

  // by adding an explicit cast, you signal the compiler that a narrowing conversion is intentional
  // there is no warning than implicit converesion in many compiler
  int b = static_cast<int>(a);

  // old format, not recommand
  int c = (int)a;

  std::cout << b << std::endl;

  return 0;
}