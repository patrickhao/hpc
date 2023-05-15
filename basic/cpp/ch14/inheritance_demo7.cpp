#include <iostream>

class A {
public:
  ~A() { std::cout << "A destructor" << std::endl; }
};

class B : public A {
public:
  ~B() { std::cout << "B destructor" << std::endl; }
};

int main() {
  // 析构函数的调用顺序和构造函数相反
  // 这种顺序保证不会出现问题，定义顺序保证指针只能指向创建的实例
  // 而析构顺序保证只有指向该实例的其他指针都释放了才会释放该实例，考虑子类有指针指向父类的情况
  // 派生类的析构函数先调用，然后是基类的，即先从最外层派生的析构函数开始调用，然后逐步向内至最内层基类
  B b;

  return 0;
}
