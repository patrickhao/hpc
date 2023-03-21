#include <iostream>
#include <string>
#include <regex>

int main() {
  std::string str1 {"123"};

  int a = std::stoi(str1);
  // The <string> module similarly offers stol(), stoll(), stoul(), stoull(), stof(), stod(), and stold()
  // all within the std namespace, to convert a string into a value of
  // respectively, type long, long long, unsigned long, unsigned long long, float, double, and long double.

  // You can define std::wstring objects that contain strings of characters of type wchar_t—the wide-character type that is built into your C++ implementation.

  // You can, for n equal to 8, 16, or 32, define std::unstring objects to store UTF-n encoded strings, using characters of type charn_t  

  // All five string types defined by the <string> module are actually just type aliases for particular instantiations of the same class template, namely, std::basic_string<CharType>.
  // std::string, for instance, is an alias for std::basic_string<char>, and std::wstring is shorthand for std::basic_string<wchar_t>.  

  // 一个简单的用法示例，对于std::wstring，在定义字符串的时候需要在前面加上L前缀
  // The L preceding the opening double quote specifies that the literal consists of characters of type wchar_t.
  // Without it, you would have a char string literal, and the statement would not compile.
  std::wstring saying {L"The tigers of wrath are wiser than the horses of instruction."};
  return 0;

  // unicode string的支持
  // Objects of type std::u8string (added in C++20) / u16string / u32string store strings of characters of type char8_t / char16_t / char32_t respectively
  // 在定义时同样需要加上前缀，注意不同编码前缀的不同
  // u8string在c++20中支持
  std::u8string quote{u8"Character is the real foundation of success."};// char8_t characters
  std::u16string question {u"Whither atrophy?"}; // char16_t characters
  std::u32string sentence {U"This sentance contains three errars."}; // char32_t characters

  // 一些方法可能没有考虑到不同字符串格式所占字节的不同，因此可能会返回一些错误的长度
  std::u8string s{u8"字符串"}; // UTF-8 encoding of the Chinese word for "string"
  std::cout << s.length() << std::endl;; // Length: 9 code units, and not 3 Chinese characters!

  // 可以使用raw string避免频繁的转义符
  // R"(...)"，字符串不包括括号
  // Any of the types of literal you have seen can be specified as raw literals by adding the same prefix as before—L, u, U, or u8—prior to the R

  auto path{ R"(C:\ProgramData\MyCompany\MySoftware\MyFile.ext)" };
  auto escape{ u8R"(The "\\" escape sequence is a backslash character, \.)" };
  // 可以识别出换行符
  auto text { LR"(First line.
  Second line.
  Third line.
  The end.)" };
  std::regex reg{ R"(\*+)" }; // Regular expression that matches one or more * characters

  // raw string内字字符串与"()"冲突时可以自己指定括号前后的字符串
  // 指定的字符串有限制
  // must not be longer than 16 characters and may not contain any parentheses, spaces, control characters, or backslash characters.
  // *()*
  auto rawStr1{R"*(The answer is "(a - b)" not "(b - a)")*"};
  // Fa-la-la-la-la()Fa-la-la-la-la 
  auto rawStr2{R"Fa-la-la-la-la(The answer is "(a - b)" not "(b - a)")Fa-la-la-la-la"};

}