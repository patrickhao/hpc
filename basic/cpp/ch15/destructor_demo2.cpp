#include <iostream>
#include <memory>
#include <vector>

class A {
public:
  // 将基类的析构函数声明为虚函数，后续所有的派生类的析构函数都是虚的
  // 就不会调用错误的析构函数了，但是注意在继承结构中，析构函数的调用是有顺序的，基类的析构函数还是会被调用
  //
  // 如果实现了多态，最好声明一个虚析构函数，避免潜在的问题出现
  virtual ~A() { std::cout << "A" << std::endl; }
};

class B : public A {
public:
  ~B() { std::cout << "B" << std::endl; }
};

int main() {

  std::vector<std::unique_ptr<A>> v;

  v.push_back(std::make_unique<A>());
  v.push_back(std::make_unique<B>());

  return 0;
}
