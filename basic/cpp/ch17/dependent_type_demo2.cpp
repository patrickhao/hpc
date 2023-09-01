#include <iostream>

template <typename T> class Base {
public:
  void baseFunc() {}

  void baseFunc2() {}

protected:
  int m_base_var;
};

template <typename T> class Derived : public Base<T> {
public:
  void derivedFunc();

protected:
  // 第三种方案，使用using告诉编译器哪些名称来自基类
  // 不可省略<T>
  using Base<T>::m_base_var;
};

// 下面的实现会报错
// 因为继承时基类都依赖于T，编译器无法确定其类型，因此也无法找到基类中的成员函数
// 因此基类的主模版不会被继承类使用
// 这种情况下调用基类的成员函数是依赖名称，但是编译器将其当成了非依赖名称，没有找到其定义因此报错
//
// 如果我们将这一推理推广开来，编译器可能不会检查模板（Derived<T>::derivedFun()
// 的模板）中的任何非依赖名称 毕竟，Base<>
// 的类模板特化可以引入任何它想要的成员名，因为将其作为为定义的
// 在引入依赖名称时，可以随便引入什么，编译器也无法判断对错，所以默认派生类中的名称都被当成非依赖名称对待
// 这就是为什么 C++ 标准规定检查 Derived<T>
// 的所有成员模板中的名称，而不考虑这些名称可能由 Base<T>
// 定义的可能性--无论是由主要 Base<> 模板，还是由类模板特化
//
/* template <typename T> void Derived<T>::derivedFunc() { */
/*   baseFunc(); */
/*   baseFunc2(); */
/*   std::cout << m_base_var << std::endl; */
/* } */

// 三种改进的方法
template <typename T> void Derived<T>::derivedFunc() {
  // 告诉编译器是成员的名称，编译器找不到会认为是基类中的
  // 编译器将其作为依赖名称对待，晚点决定具体是什么
  this->baseFunc();

  // 与this同样效果
  Base<T>::baseFunc2();

  // 第三种方式的好处是在多次调用时，只用在模版类的层面加一次using即可
  std::cout << m_base_var << std::endl;
}
