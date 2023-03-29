#include <iostream>

void show_error(const std::string& message = "Program Error") {
  std::cout << message << std::endl;
}

// All function parameters that have default values must be placed together at the end of the parameter list.


int main() {
  show_error();
  show_error("User Error");

  return 0;
}