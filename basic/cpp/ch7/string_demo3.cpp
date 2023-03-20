#include <iostream>
#include <string>
#include <cctype>

int main() {
  // 数字与字符串的转化
  std::string str1 {"a: "};
  // 直接加会将int转成字符
  str1 = str1 + std::to_string(123);
  std::cout << str1 << std::endl;

  std::string str2 {"b: "};
  // std::to_string() will always use fixed-point output with precision 6
  str2 = str2 + std::to_string(1.23);
  std::cout << str2 << std::endl;

  std::string str3 {"abc"};
  
  for (const auto& c : str3) {
    // You best add a static_cast<> here to silence compiler warnings for implicit narrowing
    // the C function toupper() returns a value of type int, and not of type char as desired
    std::cout << static_cast<char>(toupper(c)) << std::endl;
  }


  // 读取一行
  std::string str4 {};
  // 该版本的getline()定义在string中，与iostream中定义的不同
  // 不包括换行符，可手动指定终止的字符
  getline(std::cin, str4, '\n');
  std::cout << str4 << std::endl;

  // 子串
  std::string str5 {"123456789"};

  // 长度越界取全部，下标越界抛异常
  std::cout << str5.substr(1, 100) << std::endl;
  
  // 不说长度也是取全部
  std::cout << str5.substr(1) << std::endl;

  // 什么都不说就是原来的字符串
  std::cout << str5.substr() << std::endl;

  std::string str6 {"123"};
  std::string str7 {"456"};
  // 交换两个字符串，感觉swap()更好用
  // 很多标准的类型都提供了swap，例如智能指针等等
  str6.swap(str7);

  std::cout << str6 << ", " << str7 << std::endl;


  return 0;
}