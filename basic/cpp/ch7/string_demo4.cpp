#include <iostream>
#include <string>

int main() {
  // 比较字符串的方式
  // c++20中的<=>，与前面介绍的一致，相比compare更推荐<=>，其代码可读性更高
  // compare
  std::string str1 {"1"};
  std::string str2 {"2"};
  const int comp = str1.compare(str2);
  if (comp < 0) std::cout << "str1 < str2" << std::endl;
  else if (comp > 0) std::cout << "str1 > str2" << std::endl;
  else if (comp == 0) std::cout << "str1 == str2" << std::endl;

  return 0;
}