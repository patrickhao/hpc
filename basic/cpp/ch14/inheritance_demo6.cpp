#include <iostream>

class A {
private:
  int x;

public:
  A() { std::cout << "A()" << std::endl; }
  A(int _x) : x{_x} { std::cout << "A(int _x)" << std::endl; }
};

class B : public A {
public:
  // 能够通过using直接引入基类的构造函数
  // 引用父类的构造函数后相当于以下效果，相当于仅调用父类构造函数，其他部分为空的构造函数
  // B() : A{} {}
  // B(int _x) : A{_x} {}
  // 和普通的函数不同，普通函数在哪里using就是何种访问类型，但是构造函数不管在哪里using，都和父类的访问控制权限一样
  // 放在public下面使得意义理解起来更一致，因为上述规则也就相当于放在了public下面
  using A::A;
};

int main() {
  // 这里调用了直接从父类中继承过来的构造函数
  B b1;
  B b2{1};

  return 0;
}
