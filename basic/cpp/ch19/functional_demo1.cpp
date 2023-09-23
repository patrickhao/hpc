#include <functional>
#include <iostream>

int main() {
  // c++标准库内实现了一系列函数对象，通过重载这些对象的()运算符来实现类似函数的调用效果
  // 函数对象在某些时候比函数指针更加强大
  // 可以通过省略指定的类型，让编译器自己取判断更好的实现
  std::less<> StdLess;

  int a{1}, b{0};

  std::cout << StdLess(a, b) << std::endl;

  return 0;
}