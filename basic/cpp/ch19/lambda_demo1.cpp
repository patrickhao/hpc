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

  std::cout << "result: " << *findOptimum(numbers, [](int a, int b) {return a < b;}) << std::endl;;

}