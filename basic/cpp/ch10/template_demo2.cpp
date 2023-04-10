#include <__memory/temporary_buffer.h>
#include <iostream>
#include <vector>

// You can overload a function template by defining other functions with the
// same name. This allows you to define “overrides” for specific cases, without
// resorting to template specialization
// You can even overload the original template with another template
// specifically for pointer types Note that this is
template <typename T> T larger(T a, T b) { return a > b ? a : b; }

// not a specialization of the original template but instead a second, distinct
// template that will be instantiated only for pointer types
template <typename T> T *larger(T *a, T *b) { return *a > *b ? a : b; }

// it’s also possible to overload an existing template with another template
// that generates functions with completely different signature
template <typename T> const T *larger(const std::vector<T> &data) {
  const T *result{};
  for (auto &value : data) {
    // 很聪明的给value赋初值的方式
    if (!result || value > *result)
      result = &value;
  }
  return result;
}

// 多个类型参数
// 因为必须按定义的顺序指定类型，因此推荐将返回值类型放在最前面，后面的类型可以交给编译器推断
// 这里的T1和T2也可以是同种类型
template <typename RetureType, typename T1, typename T2>
RetureType larger2(const T1 &a, const T2 &b) {
  return static_cast<RetureType>(a > b ? a : b);
}

// 可以交给编译器推断返回值的类型
// 在函数调用处编译器无法推断返回值类型，但是在函数实现处编译器能够通过实现来推断返回值类型
// 返回值类型与较大值的类型相同
template <typename T1, typename T2> auto larger3(const T1 &a, const T2 &b) {
  return a > b ? a : b;
}

// 注意在上面的实现中，返回值会造成值拷贝
// 且不能通过加上const auto&解决该问题
// 因为在这种情况下vector<T>确实会返回值引用，是相同类型的引用
// 对于T1和T2相同类型的引用，返回的应该仍是引用
// 但是对于T1和T2不相同时，会返回临时变量的引用，这是不安全且不推荐的
// 可以用decltype(auto)，对于vector<T>会返回引用，对于int和double仍然返回拷贝
// decltype(auto)会提取return中表达式真正的返回值类型
// 只能在函数模版中使用，在其他函数中仍然需要根据实际情况决定
template <typename T1, typename T2>
decltype(auto) larger4(const T1 &a, const T2 &b) {
  return a > b ? a : b;
}

int main() {
  double a{1.2}, b{3.4};
  std::cout << *larger(&a, &b) << std::endl;

  int c{2};
  // 用法
  // 编译器无法推测返回值的类型，因此必须手动指定，其他的可以由编译器推断，也可以手动指定
  // 注意这里b更大，但是由于注定了返回值类型为int，进行了强制类型转换，b向下取整变成了3
  std::cout << larger2<int>(b, c) << std::endl;
  std::cout << larger2<int, double>(b, c) << std::endl;
  std::cout << larger2<int, double, int>(b, c) << std::endl;

  // 因为b较大，因此这里的返回值类型是double
  std::cout << larger3(b, c) << std::endl;

  // 因为larger3()的返回值是随着输入参数类型变化而变化的，这里b的值更大，返回值的类型是double
  // 在这里做了个隐式类型转换，将double转为int
  int ret1 = larger3(b, c);
  double ret2 = larger3(b, c);

  std::cout << ret1 << ", " << ret2 << std::endl;

  return 0;
}
