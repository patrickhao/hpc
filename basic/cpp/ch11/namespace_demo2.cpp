#include <iostream>

namespace outer {

void func_outer() { std::cout << "outer func" << std::endl; }

void func() { std::cout << "outer func" << std::endl; }

// 可以嵌套命名空间
namespace inner {
void func_inner() {
  // 内部命名空间可以直接使用外部命名空间的名字，内部命名空间同时也在外部
  func_outer();
  std::cout << "outer-inner" << std::endl;
}

void func() {
  // 可以通过这种方式调用外层空间的同名函数，具体和global
  // namespace中同名名字的使用相似
  outer::func();
  std::cout << "inner func" << std::endl;
}
} // namespace inner

// 外层命名空间调用里面的可以忽略自身namespace名字
void func2() { inner::func_inner(); }
} // namespace outer

// 可以用下述方法直接到最内层空间
namespace outer::inner {
void func3() { std::cout << "inner func3" << std::endl; }
} // namespace outer::inner

int main() {
  outer::inner::func_inner();
  outer::inner::func();

  return 0;
}
