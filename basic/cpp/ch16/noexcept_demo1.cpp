#include <iostream>

// 加上noexcept表示该函数不会有未捕获的错误，即所有错误都在函数内处理了
// 如果仍有错误，那么会直接调用std::terminate()而不是抛出该异常给上层
void someFunc() noexcept;

int main() {
  someFunc();

  return 0;
}

// 该关键字不代表该函数不能抛出异常，仍然可以自己抛出自己处理
// 只是所有的异常都在函数内部处理，如果有未捕获的异常直接终止程序而不是向上抛出
// 加了noexcept的函数，异常不能再向上rethrow
//
// c++和java的不同，java可以指定函数可能抛出哪些异常，c++已经移除该部分
void someFunc() noexcept { std::cout << "someFunc called" << std::endl; }
