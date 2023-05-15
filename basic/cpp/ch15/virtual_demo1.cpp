#include <iostream>

class A {
public:
  virtual void func() const { std::cout << "A func() call" << std::endl; }

  void callFunc() const { func(); }
};

class B : public A {
public:
  // 一旦父类中某个函数是虚函数了，后续所有子类中该函数的定义也是虚函数，子类定义中加不加virtual都是一样的
  // 这里不用显示加上override也能实现多态
  //
  // 对于虚函数，派生类中该函数的定义必须和基类中的虚函数一致，即函数签名一致，且返回值类型也必须一致
  // 对于派生类来说，当基类函数中的返回值是指针或引用时，派生类的函数可以返回更加具体的类型
  //
  // 虚函数不能是函数模版，虚函数也不能是static函数
  // 在调用static成员函数时，最好通过类名前缀来调用而不是实例
  void func() const { std::cout << "B func() call" << std::endl; }
};

class C : public A {
public:
  // 派生类中的函数只会重载函数签名与其相同的基类虚函数，如果有不同，派生类的同名函数会覆盖基类函数，需要靠类名来指定调用哪个实现
  // 函数参数列表和const不同，虚函数的机制也不会工作，下面的例子中，虽然都是func()，但是这里的覆盖了基类中的func()，是一个全新的函数
  // 通过基类指针调用时，调用的是基类中的func()，这里虚函数机制失效，变成了静态的，因此调用的是基类实现
  void func() { std::cout << "C func() call" << std::endl; }
};

class D : public B {
public:
  // override会让编译器检查当前是否重载了基类中的虚函数，如果没有重载会报错
  // 但是注意不是加上override才会重载基类虚函数，只要函数签名和返回值与基类虚函数一致就重载了
  // override额外提供了一层更安全的检查，避免因为函数签名不同覆盖基类虚函数而不是重载虚函数带来的问题
  // 建议所有的虚函数实现都加上override，会额外检查所务并且改变基类中虚函数定义时，会提醒修改所有派生类中的重载，否则会报错
  //
  // 使用final防止之后的派生类再重载该函数，多态的链条到此为止，派生类尝试重载会报错
  // override和final的顺序无要求，但都要在const之后
  void func() const override final {
    std::cout << "D func() call" << std::endl;
  }
};

// 给类加上final之后该类不能再作为基类被其他类继承
class E final : public D {};

int main() {
  B b;
  C c;

  const A *a1 = &b;
  const A *a2 = &c;

  a1->callFunc();
  a2->callFunc();

  D d;

  const B *b1 = &d;
  // 这里因为B中的func()仍是虚函数，虽然没有显示指定，所以调用的是D中的func()实现
  b1->func();

  return 0;
}
