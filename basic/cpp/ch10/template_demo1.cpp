#include <iostream>
#include <string>

template <typename T> T larger(T a, T b) { return a > b ? a : b; }

// 加上函数模版的特殊情况，指定某种类型下的函数实现，但是不推荐这种方式，原因如下
// We recommend you never use function template specialization. to customize a
// function template for specific types, you should overload the function
// template instead, either with a regular function or another function
// template. We discuss these options in the next section. Function overloads
// behave more intuitively in general than function template specializations.
template <> double *larger(double *a, double *b) { return (*a > *b ? a : b); }

int main() {
  double a{1.2}, b{3.4};

  // 无需指定类型，编译器会自动推断
  std::cout << larger(a, b) << std::endl;

  // 对于函数模版，编译器不会进行隐式的变量转换，需要手动转换，或者使用下面的方法，手动指定类型
  // 在这种情况下，编译器知道用户的意图，因此会进行隐式转换，若不指定，编译器无法确定返回值的类型，也就不会进行隐式转换
  int c{10};
  std::cout << larger<double>(c, b) << std::endl;

  // 由于函数实现的问题，编译器比较的是地址的大小，而非地址内存的值的大小
  // 每次输出的值可能不一样，因为地址的分配是不可预测的，不过这里是stack上分配的a和b，因此更可能输出a
  // 加上上面的函数模版特殊情况的实现，下面的代码就正确了
  std::cout << *larger(&a, &b) << std::endl;

  return 0;
}
