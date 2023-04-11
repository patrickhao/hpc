#include <iostream>

void func() { std::cout << "global namespace" << std::endl; }

namespace mySpace {
void func() { std::cout << "mySpace namespace" << std::endl; }

void callFunc() {
  // 如果命名空间中有和global namespace中名字相同的方法，会被覆盖
  func();
  // 可以通过下面的方法调用global namespace中的方法
  ::func();
}
} // namespace mySpace
// Note that no semicolon is required after the closing brace in a namespace
// definition

// 能接上之前的命名空间，不一定都要写在一起
namespace mySpace {
// 同一个命名空间中的名称可以直接使用
void func2() { func(); }
} // namespace mySpace

// You must not include the main() function within a namespace. the runtime
// environment expects main() to be defined in the global namespace.
int main() {
  int a{10};

  mySpace::callFunc();

  return 0;
}
