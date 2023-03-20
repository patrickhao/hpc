#include <iostream>
#include <string>

int main() {
  std::string word {"123"};
  // 下面的是有问题的
  // 不能直接将两个非string字符串想加，因为普通的字符串表示没有重载+运算符，必须保证运算符的任何一侧有string类型参与
  // std::string description {" whippersnapper" + " " + word}; // Wrong!!
  // 下面这种形式编译器会这样看
  // std::string description {(" whippersnapper" + " ") + word}; // Wrong!!
  // 下面这种没问题，先进行后面的运算，该运算符已经被重载，得到新的string后与"whippersnapper"的加法操作也可以进行了
  // 单个字符也可以，注意点同上
  std::string description {" whippersnapper" + (" " + word)}; // Wrong!!

  // 有如下解决办法（部分）
  // 多个literals中间无需加上+，编译器会将他们看成一个literal
  std::string str1 {"whippersnapper" "" + word};

  // 可以通过在后面加s转成std::string
  // 需要using namespace std::string_literals
  // std::string str2 {"whippersnapper"s + "" + word};

  // append
  std::string sentence {};
  std::string compliment("~~~ What a beautiful name... ~~~");
  sentence.append("123");
  sentence.append(compliment, 3, 22); // Appends " What a beautiful name"
  sentence.append(3, '!'); // Appends "!!!"
  std::cout << sentence << std::endl;

  std::string str3 = "123";
  // 下面这种情况，部分编译器会将字符看成两个整数加起来再根据ASCII转成字符
  // str3 = ',' + ' ' + str3;
  std::cout << str3 << std::endl;

  return 0;
}