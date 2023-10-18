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

  int number_to_search_for{3};

  // []中可以包含capture clause，表示当前作用域内的变量在lambda表达式中是否可以访问
  // 里面什么有没有表示只能访问lambda表达式中定义的本地变量
  // 如果用了capture clause，表示当前作用域内的所有变量包含在lambda表达式的定义中，既可以访问当前作用域内的所有变量
  // 这里有两种capture模式，两者只能选其一，是=和&，表示传值和引用
  // 
  // 下方的例子中访问当前作用域内所有变量的值
  // 但是这些变量无法改变，因为是传值
  // 
  // 这种传递了作用域内变量的lambda函数，实际上是一个重载了()运算符的类的实例，且类的构造函数中传入了用到的相关作用域内变量
  // 这个的具体实现和上方的Nearer类非常近似
  auto nearer {[=](int x, int y) {
    // 函数内可以访问当前作用域内的变量，这里就是numbers和number_to_search_for
    // 看起来是直接访问的作用域内的变量，实际上是访问的生成的类中的同名成员
    // 对于=没有用到的不会捕捉
    return std::abs(x - number_to_search_for) < std::abs(y - number_to_search_for);
  }};

  std::cout << "result: " << *findOptimum(numbers, nearer) << std::endl;
}