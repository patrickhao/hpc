#include <iostream>

int main() {
  // Type wchar_t is a fundamental type intended for character sets where a single character does not fit into one byte
  // wide character
  // define wide-character literals
  // prefix them with L
  wchar_t z {L'Z'};

  // g++下wchar_t占4 byte，char占1 byte
  // wchar_t的问题就是不同平台以及编译器下面的size不同
  // 可以使用其他类型如char8_t, char16_t, char32_t等
  std::cout << sizeof(wchar_t) << ", " << sizeof(char) << std::endl;

  // Values of these types are intended to store characters encoded as UTF-8, UTF-16, or UTF-32
  // respectively, and their sizes are the same on all common platforms
  // The prefixes u8, u, and U to the literals indicate that they are UTF-8, UTF-16, and UTF-32
  // the char8_t type was introduced in C++20
  char8_t yen {u8'\x00A5'}; // Initialized with UTF-8 code for the yen sign (¥)
  char16_t delta {u'\x0394'}; // Initialized with UTF-16 code for Greek Delta (Δ) 
  char32_t ya {U'\x044f'}; // Initialized with UTF-32 code for cyrillic letter ya (я)

  wchar_t cc {L'\x00E7'};

  // Your keyboard may not have keys for representing other national language characters
  // but you can still create them using hexadecimal notation
  std::cout << cc << std::endl;

  return 0;
}