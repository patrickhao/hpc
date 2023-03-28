#include <iostream>

void func1(int a, double b) {
  std::cout << "int, double" << std::endl;

  // 没有return语句默认是return;
  // 若返回值不是void，没有return则会报错
  // 除非在main()函数中，main()函数没有return最后会默认return 0;
};

void func1(double b, int a) {
  std::cout << "double, int" << std::endl;
};

// 但是返回值不同会报错，因为调用的时候无法根据函数名和参数类型推断出该调用哪个实现
// void func1(int a, double b) {
//   std::cout << "int, double" << std::endl;
// };

void func2(int a, double b) {
  std::cout << "func2" << std::endl;
}

int func3(int a) {

  // 返回的是一个拷贝，该拷贝在调用函数处可以访问
  return 2 * a;
}

int func4() {
  double a {1.0} ;
  // 若类型不匹配会进行类型转换
  return a;
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
  // narrowing conversion时部分编译器可能会报错或者给出警告
  // 如果无法转换，编译器也会报错
  func2(b, c);

  return 0;
}