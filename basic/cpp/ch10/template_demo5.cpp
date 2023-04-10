#include <iostream>

template <typename T> auto sqr1(T x) { return x * x; }

// 更加简洁的定义模版的方式，用auto
// 用在函数参数中的auto叫做abbreviated function template
auto sqr2(auto x) { return x * x; }

// 也可以用auto*, auto&, const auto&
auto cube(const auto &x) { return x * x * x; }

// 不会将返回值中的auto对应到typename，但是对于函数参数中的auto，会一一对应到typename上
// 下面两种定义是一样的
const auto &larger1(const auto &a, const auto &b);

template <typename T1, typename T2>
const auto &larger2(const T1 &a, const T2 &b);

// 也可以混用explicit和implicit
template <typename T>
const T &mixAndMatch(auto *mix, const T &match1, const T &match2);

// 对于一些情况只能用之前的声明模版的方法，例如typename需要多次使用，implicit只会为每个auto分配一个typename，无法复用
template <typename T> const T &larger(const T &a, const T &b);

// 或者函数的实现中用到了typename T，因为auto的typename是隐式的，无法使用其
template <typename T> auto createConsecutiveVector(const T &from, const T &to) {
  std::vector<T> result;
  for (T t = from; t < to; ++t)
    result.push_back(t);
  return result;
}

int main() {
  // 用的时候可以和正常的template一样，例如指定类型等
  std::cout << sqr2<int>(3) << std::endl;
  return 0;
}
