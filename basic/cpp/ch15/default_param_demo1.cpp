#include <iostream>

class A {
public:
  virtual void func(int i = 10) const {
    std::cout << "A func() i = " << i << std::endl;
  }
};

class B : public A {
public:
  void func(int i = 100) const override {
    std::cout << "B func() i = " << i << std::endl;
  }
};
int main() {
  const A *aPtr{};

  B b;
  aPtr = &b;

  // 函数的默认参数值在编译时处理，因此对于虚函数的参数默认值，只会使用基类的，派生类中的不会产生作用
  // 尽管函数是执行的派生类中的实现，但是参数默认值是基类函数中的
  aPtr->func();

  // 使用派生类实例调用函数时才会使用派生类的默认值
  b.func();

  return 0;
}
