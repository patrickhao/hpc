#include <iostream>
#include <vector>

// using可以结合template一起使用
// 可以使用using给函数指针取个别名，这样代码可读性会更好
template <typename T>
using Comparison = bool (*)(const T&, const T&);

template <typename T>
const T* findOptimum(const std::vector<T> &values, Comparison<T> compare);

int main() {
  // 通过using取的别名声明新的函数指针变量，这里指向nullptr
  Comparison<std::string> string_compare{};
  return 0;
}