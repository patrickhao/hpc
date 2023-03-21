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

  std::string word1 {"A jackhammer"};
  std::string word2 {"jack"};

  // 可以在compare中加入参数比较子串
  // 比较word1从下标2开始，长度为4个长度的子串
  const int result {word1.compare(2, word2.length(), word2)};

  if (result == 0) {
    std::cout << word1 << " contains " << word2 << " starting at index 2" << std::endl;
  }

  // 不仅能取word1的子串，还能取word2的子串
  const int result2 {word1.compare(3, 3, word2, 1, 3)};
  // 省略默认截到最后
  const int result3 {word1.compare(3, 3, word2, 1)};

  std::cout << result2 << ", " << result3 << std::endl;

  // 判断是否以某字符串/字符开头结尾
  // c++20支持
  // std::string str3 {"1234567"};
  // bool b1 = str3.starts_with("123");
  // bool b2 = str3.starts_with('1');
  // bool b3 = str3.ends_with("567");

  // 查找字符串
  std::string str3 {"123456712345687"};

  // 注意find返回的是一个下标，返回的不是查找的结果
  std::cout << str3.find("1") << std::endl;
  // std::string::npos通常是size_t能表示的最大整数，一般不会有这么长的字符串
  if (str3.find("x") == std::string::npos) {
    std::cout << "not find" << std::endl;
  }

  // 从特定位置开始查找
  // 返回的是整个字符串中的下标而不是子串中的下标
  std::cout << str3.find("3", 1) << std::endl;
  std::cout << str3.find("3", 7) << std::endl;

  // 查找子串
  // 第二个参数，str3中开始查找的下标
  // 第三个参数，"123"中取前两个组成子串进行搜索，即搜索的是"12"
  std::cout << str3.find("123", 1, 2) << std::endl;

  // 查找一个字符集合中的任意一个字符串
  std::string text {"Smith, where Jones had had \"had had\", had had \"had\"." " \"Had had\" had had the examiners' approval."};

  std::string seperators {",.\""};
  // 查找",.\""中任意一个字符
  std::cout << text.find_first_of(seperators) << std::endl;
  std::cout << text.find_first_of("AaEeIiOoUu") << std::endl;
  // 从后面往前查找
  std::cout << text.find_last_of(seperators) << std::endl;

  // 表示从text2的第几位开始
  std::string text2 {"a\"b.c,"};
  std::cout << text2.find_first_of(seperators, 2) << std::endl;

  // 找不在给定字符串集合中的
  std::cout << text.find_first_not_of("AaEeIiOoUu") << std::endl;

  // reverse search
  // 其余操作和find相似
  std::string text3 {"1234512345"};
  std::cout << text3.rfind("3") << std::endl;


  return 0;
}