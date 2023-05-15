#include <iostream>

class A {
private:
public:
  void showFunc() { func(); }

  void func() { std::cout << "A func()" << std::endl; }
};

class B : public A {
private:
public:
  void func() { std::cout << "B func()" << std::endl; }
};

int main() {
  A a;
  B b;
  A *bPtr{&b};
  a.showFunc(); // A
  a.func();     // A

  // 这里调用的showFunc()是父类中的，这里是静态绑定cout
  // 在编译时就为showFunc()绑定了A::func()，因此输出的是A
  b.showFunc(); // A
  b.func();     // B

  // 这里通过基类指针调用函数，这里也是静态确定的，因此调用的还是父类中的方法，输出A
  // 静态函数调用只取决于指针类型，而不是其指向类的具体类型
  // 基类中隐式的this指针调用，所调用的具体函数也是静态确定了，参考上面A::showFunc()
  bPtr->showFunc(); // A
  bPtr->func();     // A

  return 0;
}
