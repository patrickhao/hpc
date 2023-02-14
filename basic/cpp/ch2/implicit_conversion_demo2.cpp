#include <iostream>

int main() {
  int y {};
  double z {5.0};

  y = z;
  y = static_cast<int>(z);

  return 0;
}