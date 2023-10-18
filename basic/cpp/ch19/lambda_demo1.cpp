#include <iostream>
#include <vector>

template <typename T, typename Comparison>
const T *findOptimum(const std::vector<T> &values, Comparison compare) {
  if (values.empty()) {
    return nullptr;
  }

  const T *optimum = &values[0];

  for (size_t i{1}; i < values.size(); ++i) {
    if (compare(values[i], *optimum)) {
      optimum = &values[i];
    }
  }
  return optimum;
}

class Nearer {
public:
  Nearer(int value) : m_value{value} {}

  bool operator()(int x, int y) const {
    return std::abs(x - m_value) < std::abs(y - m_value);
  }

private:
  int m_value;
};

bool less(int a, int b) {
  return a < b;
}

int main() {
  std::vector numbers{1, 2, 3, 4, 5, 6, 7};

  // 对于不需要外部数据的lambda表达式，lambda表达式不再是对象函数，将被会隐式转化为等价的函数指针，下方例子中的lambda表达式不依赖外部的变量，因此转化为函数指针bool(*)(int, int)形式 
  // 当lambda表达式中对外部数据有依赖，即需要依赖成员变量，此时类型转化为函数指针的形式无法很好的满足要求，lambda表达式此时将会被当作对象函数
  std::cout << "result: " << *findOptimum(numbers, [](int a, int b) {return a < b;}) << std::endl;;

  // 可以通过这种方式定义lambda表达式的名称
  auto larger = [](int a, int b) { return a > b; };
  std::cout << "result: " << *findOptimum(numbers, larger) << std::endl;
}