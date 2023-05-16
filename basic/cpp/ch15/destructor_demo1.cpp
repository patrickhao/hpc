#include <iostream>
#include <memory>
#include <vector>

class A {
public:
  ~A() { std::cout << "A" << std::endl; }
};

class B : public A {
public:
  ~B() { std::cout << "B" << std::endl; }
};

int main() {

  std::vector<std::unique_ptr<A>> v;

  v.push_back(std::make_unique<A>());
  // 这里虚构函数没有声明为虚的，因此还是静态绑定的，这里调用的都是基类的析构函数
  // 调用错误的析构函数可能会导致内存泄漏等问题，没有释放派生类中分配的空间
  v.push_back(std::make_unique<B>());

  return 0;
}
