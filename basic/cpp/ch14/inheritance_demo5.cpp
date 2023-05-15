#include <iostream>

class A {
private:
  int x;

public:
  A() = delete;
  A(int _x) : x{_x} {}
};

class B : public A {
public:
  // 如果基类的默认构造函数被删除了，不管是显示还是隐式的
  // 那么如果将派生类的构造函数声明为default，也就相当于删除了派生类的构造函数
  // 因为这里的default也继承了父类的默认构造函数，这里父类的构造函数已经删除了
  // 因此子类的行为和父类一致
  // 相当于B() = delete;
  // 这里不仅是这种显示的声明，如果B中没有构造函数，编译器生成的构造函数也会出现该问题
  B() = default;
  B(int _x) : A{_x} {}
};

class AA {
private:
  int x;

  AA() = default;

public:
  AA(int _x) : x{_x} {}
};

class BB : public AA {
public:
  // 这里如果父类默认构造函数是private，子类中也访问不到默认的父类构造函数
  // 因此这里的BB()的相当于delete了
  BB() = default;
  BB(int _x) : AA{_x} {}
};

int main() {
  /* B b; // 错误，已经没有默认构造函数了 */
  return 0;
}
