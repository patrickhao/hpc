#include <iostream>

long sum(long a, long b);

long product(long a, long b);

int main() {
  long (*func_ptr)(long, long){};

  func_ptr = &sum;

  std::cout << func_ptr(3, 5) << std::endl;

  // 取址符号&可加可不加，就像函数指针的使用也不需要解引用
  func_ptr = product;

  std::cout << func_ptr(3, 5) << std::endl;
}

long sum(long a, long b) { return a + b; }

long product(long a, long b) { return a * b; }
