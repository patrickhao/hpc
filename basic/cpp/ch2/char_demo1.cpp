#include <iostream>

int main() {
  char c;

  // When you use >> to read from a stream into a variable of type char, the first nonwhitespace character will be stored
  // This means you can’t read whitespace characters in this way
  // When you use >> to read from a stream into a variable of type char, the first nonwhitespace character will be stored
  // This means you can’t read whitespace characters in this way
  std::cin >> c;

  std::cout << c << std::endl;

  return 0;
}