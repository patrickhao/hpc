#include <iostream>
#include <vector>

template <typename T, typename Comparison>
const T *findOptimum(const std::vector<T> &values, Comparison compare) {
  if (values.empty()) {
    // 这里指针可以直接返回nullptr，但是如果返回值是引用，那么可以通过定义一个特殊的变量作为空引用，此处返回该变量即可
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

bool longer(const std::string &, const std::string &);

int main() {
  std::vector numbers{1, 2, 3, 4, 5, 6, 7};

  // 函数对象比函数指针更强大，当出现成员变量的时候，就需要函数对象了
  // 这里的例子是找到和用户指定的值最相近的值，这里由用户指定的值3
  // 通过普通的函数指针很难漂亮的实现，但是通过重载()运算符的函数对象，可以为这个对象加入成员变量很好的实现这个功能
  std::cout << "result: " << *findOptimum(numbers, Nearer{3}) << std::endl;

}