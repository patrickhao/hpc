#include <iostream>

void func1(int a, double b) {
  std::cout << "int, double" << std::endl;
};

void func1(double b, int a) {
  std::cout << "double, int" << std::endl;
};

void func2(int a, double b) {
  std::cout << "func2" << std::endl;
}

int main() {
  int a {1};
  double b {1.0};

  // 可以重载
  func1(a, b);
  func1(b, a);

  // 如果类型不匹配首先会进行隐式类型转换，如果转换失败再报错
  int c {1};
  // 下面这种情况类型转换成功
  func2(a, c);
  // narrowing conversion时部分编译器可能会报错
  func2(b, c);

  return 0;
}