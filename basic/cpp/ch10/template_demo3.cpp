#include <iostream>

template <typename T, int lower, int upper> bool is_in_range(const T &value) {
  return (value >= lower) && (value <= upper);
}

// 可以使用auto，让编译器自动推断类型
template <typename T, auto lower, auto upper>
bool is_in_range2(const T &value) {
  return (value >= lower) && (value <= upper);
}

// 也可以使用T
template <typename T, T lower, T upper> bool is_in_range3(const T &value) {
  return (value >= lower) && (value <= upper);
}

// 也可以将non-type参数放前面，简化调用时需要指定的参数
// 但是不能使用T了，因为T在non-type处还没声明
// 下面这个实现目前来看是比较好的一种，即只吃了边界不同的类型，也简化了函数调用需要指定的参数
template <auto lower, auto upper, typename T>
bool is_in_range4(const T &value) {
  return (value >= lower) && (value <= upper);
}

int main() {
  // 编译器需要在编译阶段就知道参数的值，因此必须是const常量或constexpr或consteval
  // the limits of is_in_range() you should probably use regular function
  // parameters over template parameters. Function parameters give you the
  // flexibility of being able to pass values that are calculated at runtime,
  // whereas with template parameters you must supply the limits at compile time
  std::cout << is_in_range<int, 0, 100>(10) << std::endl;
  // 下面的例子也可以
  // Once you omit the const, however, i is no longer a constant, and the code
  // will fail to compile. All template parameters, both type and non-type, need
  // to be evaluated at compile time, while generating the concrete function
  // instantiation from the template.
  const int i{1};
  std::cout << is_in_range<int, i, 10 * i>(3) << std::endl;

  // 改变参数声明的顺序可以简化调用时需要指定的参数，将编译器能够推断的都往后放放
  std::cout << is_in_range4<i, 10 * i>(3) << std::endl;

  return 0;
}
