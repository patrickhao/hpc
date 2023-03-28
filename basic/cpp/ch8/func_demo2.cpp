#include <iostream>
using namespace std;

// 函数原型，可以提前定义，应对一下情况
// A调用B，B调用A，这种情况下需要提前定义
// 可能定义都在一个头文件，实现在另一个头文件
// 定义或实现需要在调用之前
// 帮助理解函数的意义，在定义里的参数名和实现里的可以不一样，因此长一点也没关系
double power(double value, int exponent);

// 只需要给编译器提供足够信息，因此可以不用带上参数名
double power2(double, int);

int main() {


  return 0;
}

double power(double x, int n) {
  return 0;
}

double power2(double x, int n) {
  return 0;
}