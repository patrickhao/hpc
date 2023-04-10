#include <iostream>

// A static variable that you define within a function is created the first time its definition is executed.
// It then continues to exist until the program terminates
unsigned int nextInteger() {
  // 只在第一次运行nextInteger时将其初始化为0，之后的调用操作的都是同一个count
  // static变量默认是初始化为0的，这与普通变量不同，因此最后的{0}可以省略
  static unsigned int count {0};
  return ++count;
}

int main() {
  std::cout << nextInteger() << std::endl;
  std::cout << nextInteger() << std::endl;

  return 0;
}