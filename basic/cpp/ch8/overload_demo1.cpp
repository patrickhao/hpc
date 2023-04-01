#include <iostream>

// 仅仅返回值不同不算重载，会报错，因为返回值不同无法在调用时确定到底调用哪个函数

// 不同类型的指针算重载
// 注意下面这个例子更适合用模版来解决
int largest(int* pValues, size_t count) {
  return 0;
}

int largest(double* pValues, size_t count) {
  return 0;
}

// 注意传入指针和传入数组一样，并且第一维度是忽略的，因此下面两种函数实际上和上方的一样
// int largest(double pValues[], size_t count) {
//   return 0;
// }

// int largest(double pValues[10], size_t count) {
//   return 0;
// }

// 重载引用也是不允许的，因为编译器无法判断调用的是哪个函数
// 下方的两个函数也是有问题的
void doIt(std::string number) {

}

void doIt(std::string& number) {

}

double larger(double a, double b) {
  std::cout << "double larger() called" << std::endl;
  return a > b ? a : b;
}

long& larger(long& a, long& b) {
  std::cout << "long larger() called" << std::endl;
  return a > b ? a : b;
}

// 要想下面的函数调用long larger()，可以转成const引用参数，这样编译器知道不会改变其值
// 会传入临时变量，但是此时返回值如果是引用，那么也是该临时变量的地址，感觉有点奇怪，可以返回数据的副本，感觉会好一些
// 如果要返回引用，也要是const，因为编译器无法将const转为非const
const long& larger(const long& a, const long& b) {
  std::cout << "long larger() called" << std::endl;
  return a > b ? a : b;
}

int main() {
  double a {1.5}, b {2.5};
  larger(a, b);
  // 这次调用的也是double larger()
  // static_cast转出来的是临时变量，编译器不会用临时变量初始化指向非const引用
  larger(static_cast<long>(a), static_cast<long>(b));

  return 0;
}