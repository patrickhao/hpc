#include <iostream>
#include <string>

int main() {
  std::string empty; // An empty string

  std::string s1 {"123"}; // 都加上了'\0'，为了与c风格的程序兼容，但是length()和size()返回的长度不包括终止符

  std::cout << s1.length() << std::endl;
  std::cout << s1.size() << std::endl;

  // c_str()返回的是const char指针，不允许修改
  const char* cPtr1 = s1.c_str();

  // data()返回的char指针是不是const取决于string本身的类型，若string是const的，则返回const指针
  // 该特性仅在c++17之后，之前都是和c_str()一样返回const char指针
  char* cPtr2 = s1.data();
  
  // 返回的指针指向string内字符串存储的地方，改变该指针指向数据的值，相应的string的值也会改变
  cPtr2[1] = 'i';
  std::cout << cPtr2 << std::endl;
  std::cout << s1 << std::endl;

  // 用给定字符串的前五个字符初始化
  std::string part_literal { "Least said soonest mended.", 5 }; // "Least"

  // 不能通过单个字符初始化string，必须用双引号包起来，但是可以让字符重复n次
  // 和vector填充的方式类似
  std::string sleeping(6, 'z');
  std::cout << sleeping << std::endl;

  std::string light_sleeper(1, 'z');
  std::cout << light_sleeper << std::endl;


  return 0;
}