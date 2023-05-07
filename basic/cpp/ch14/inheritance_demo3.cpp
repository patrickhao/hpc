#include <iostream>

class A {
private:
  int x;

public:
  // 默认的构造函数就算不使用默认实现，也是默认构造函数，注意区分默认实现和默认构造函数
  A() { std::cout << "A()" << std::endl; }

  A(int _x) : x{_x} { std::cout << "A(int)" << std::endl; }
};

class B : public A {
public:
  B() { std::cout << "B()" << std::endl; }
  // 可以指定默认的构造函数
  // 因为c++支持多继承，因此这里直接指定到基类名
  // 派生类中基类构造函数的调用和其他地方使用一样，使用派生类中的参数初始化基类成员
  B(int _x) : A{_x} {}
};

class C : public B {
public:
  C() { std::cout << "C()" << std::endl; }
};

int main() {
  // 实例化类是先会调用基类的构造函数，然后是子类
  // 多级继承会逐步找父类，知道是最开始的基类，然后从基类开始调用构造函数
  // 派生类中有一个完整的基类，先创建基类在逐步创建派生类
  // 相较于调用默认的构造函数，也可以手动置顶调用哪一个构造函数
  // 如果没有指定则会调用default，重载了默认的会调用空参数的那个构造函数
  C c;

  B b{1};
  return 0;
}
