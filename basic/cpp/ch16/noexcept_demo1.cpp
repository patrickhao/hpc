#include <iostream>

// 加上noexcept表示该函数不会有未捕获的错误，即所有错误都在函数内处理了
// 如果仍有错误，那么会直接调用std::terminate()而不是抛出该异常给上层
// 任何对noexcept的重载都必须是noexcept，且其必须在const之后override之前
void someFunc() noexcept;

class A {
  // Starting with C++11, destructors are normally implicitly noexcept
  // the exception will never leave the destructor. Instead, std::terminate()
  // shall always be called
  ~A(){};
};

class B {
  // 技术上可以让析构函数抛出异常，但是不建议这么做，尽可能不让异常抛出析构函数
  // Unless you really know what you’re doing, never throw exceptions from a
  // destructor!
  ~B() noexcept(false) {}
};

int main() {
  someFunc();

  return 0;
}

// 该关键字不代表该函数不能抛出异常，仍然可以自己抛出自己处理
// 只是所有的异常都在函数内部处理，如果有未捕获的异常直接终止程序而不是向上抛出
// 加了noexcept的函数，异常不能再向上rethrow
//
// c++和java的不同，java可以指定函数可能抛出哪些异常，c++已经移除该部分
//
// 实现的时候，不加virtual和override，要加noexcept
void someFunc() noexcept { std::cout << "someFunc called" << std::endl; }
