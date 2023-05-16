#include <iostream>
#include <vector>

class A {
public:
  virtual void func() const { std::cout << "A" << std::endl; }
};

class B : public A {
public:
  void func() const override { std::cout << "B" << std::endl; }
};

// 可以将参数设置为基类的引用类型，可以传递任何派生类或基类实例从而实现多态
void showFunc(const A &a) {
  // 因为参数是指向基类的引用，编译器会动态绑定函数的类型
  a.func();
}

int main() {
  A a;
  showFunc(a);

  B b;
  showFunc(b);

  // 另一种通过引用实现多态的方法，这里的test调用的还是B中的func()实现
  // 因为指针中存储的实际上是B的实例，这里引用也被解析到了B的实例中
  const A *aPtr = &b;
  const A &test{*aPtr};
  test.func();

  // 也可以直接指定，这里使用方式和指针类似
  const A &test2 = b;
  test2.func();

  return 0;
}
