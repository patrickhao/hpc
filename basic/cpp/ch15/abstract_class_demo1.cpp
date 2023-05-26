#include <iostream>

class A {
protected:
  int x;
  // 因为不能有实例，因此可以将抽象类的构造函数声明在protected下面
  // 这样只有派生类能够调用该构造函数，防止在其他未定义的地方调用构造函数
  A(int _x) : x{_x} {}

public:
  // 可以将函数声明为纯虚函数，含有纯虚函数的类成为抽象类，抽象类不能有实例
  virtual void func() = 0;
};

class B : public A {
public:
  // 注意纯虚函数不能被静态调用，只能在运行时动态调用
  // 其目的就是用来实现多态
  // 因此通过指定类名加函数名的方法编译器会报错
  virtual void func() override { std::cout << "func" << std::endl; }
};

// 如果继承后不实现纯虚函数，那么这个类仍然是抽象类，不能实例话
class C : public A {};

// 对于不含任何成员变量，只含纯虚函数的抽象类，可以将其作为接口使用
//
// 如果没有实现接口中的全部方法，此时该类仍然是抽象类，将其作为普通类使用会报错
// 这种办法也可以一定程度上保护代码的完整性和正确性
// 因此这也算是一定程度上保证了接口的使用规则，即必须实现全部方法，否则编译器报错
class SomeInterface {
public:
  virtual void func1() = 0;

  virtual void func2() = 0;
};

int main() {}
