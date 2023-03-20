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
  std::string part_literal { "Least said soonest mended.", 5 }; // "Least"，相当于0, 5
  std::cout << part_literal << std::endl;
  // 也可以指定用哪一段子串初始化，从6开始，往后的4个字符串
  std::string part_literal2 { "Least said soonest mended.", 6, 4}; // "said"
  std::cout << part_literal2 << std::endl;

  std::string originStr {"Consistency is the key to success"}; 
  // 如果是传的字符串，后面的数表示取前多少个字符
  std::string part_literal3 {"Consistency is the key to success", 15}; // Consistency is 
  // 如果如果传进去的是string，则后面的数是指开始的地址，默认一直到结束
  // 传的是字符串的情况下，这种和substr()的功能类似，但是与上面的有点不一致，注意区分一下
  std::string part_literal4 {originStr, 15}; // the key to success
  std::cout << part_literal3 << std::endl;
  std::cout << part_literal4 << std::endl;

  // 不能通过单个字符初始化string，必须用双引号包起来，但是可以让字符重复n次
  // 和vector填充的方式类似
  std::string sleeping(6, 'z');
  std::cout << sleeping << std::endl;

  std::string light_sleeper(1, 'z');
  std::cout << light_sleeper << std::endl;


  return 0;
}