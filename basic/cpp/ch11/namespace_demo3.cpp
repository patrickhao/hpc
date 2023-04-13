#include <iostream>

namespace myspace {
void func1();
void func2();
} // namespace myspace

int main() {
  myspace::func1();
  myspace::func2();
  return 0;
}

// 实现命名空间中函数的几种方式
// 在命名空间中实现
namespace myspace {
void func1() { std::cout << "func1" << std::endl; }
} // namespace myspace

// 直接通过命名空间指向函数并实现
void myspace::func2() { std::cout << "func2" << std::endl; }
