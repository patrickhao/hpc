#include <iostream>

class A {
public:
  virtual void func() { std::cout << "A func" << std::endl; }
};

class B : public A {
public:
  virtual void func() override { std::cout << "B func" << std::endl; }

  // 可以指定到基类中的函数实现
  // 对于通过类指针的函数调用，要么是静态确定的函数调用，例如下方指定到具体类实现的函数调用
  // 要么是动态的，在运行时才绑定的，例如上方的两个func()函数
  void callFunc() {
    // 指定到类中的具体函数使得能够在编译阶段静态确定调用的函数
    A::func();
  }
};

int main() {
  A *a = new B;

  // 可以显示告诉编译器调用基类中的函数实现
  a->func();

  // 能在派生类指针中，通过指定到基类的实现调用基类中的函数
  // 对于指向基类的指针，不能指定其派生类中的函数实现，只能向上显示调用，而不能向下显示调用，因为基类中没有派生类中的信息
  a->A::func();

  B b;
  // 不通过指针也能实现
  b.func();
  b.A::func();

  b.callFunc();

  return 0;
}
