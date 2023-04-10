#include <iostream>

template <typename T, size_t N> T average(const T (&array)[N]) {
  T sum{};
  for (size_t i{}; i < N; ++i)
    sum += array[i];
  return sum / N;
}

int main() {
  // 编译器能够推断数组长度
  std::cout << average({1.0, 2.0, 3.0}) << std::endl;

  return 0;
}
