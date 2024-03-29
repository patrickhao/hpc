#include <iostream>

class A {
public:
  int m_value{10};

  void func1(int x) { std::cout << "A func1 int call" << std::endl; }
  void func1(float x) { std::cout << "A func1 float call" << std::endl; }

  void func2(int x) { std::cout << "A func2 int call" << std::endl; }
};

class B : public A {
public:
  int m_value{20};

  int total() {
    // m_value是当前作用域内的值，想要引用父类的m_value需要加上父类的名称，此处类似多级命名空间中重复名称的处理
    return m_value + A::m_value;
  }

  // 函数名相同时，这里并不是函数重载，因为函数重载需要在相同的作用域中
  // 继承类的函数重载需要在函数末尾加上override
  // 派生类中的函数会覆盖基类中的同名函数，即使参数列表不同，这里不再同一个作用域中，不产生重载
  void func1(double x) { std::cout << "B func2 call" << std::endl; }

  // 如果想要引入父类中的同名函数，使用using，因为参数列表不同，有不同的函数签名，引入后编译器会区分两者
  using A::func1;

  // 另一种情况是有相同的参数列表的情况，可以通过基类名调用基类中的函数
  void func2(int x) { std::cout << "B func2 int call" << std::endl; }
};

int main() {
  B test;
  std::cout << test.total() << std::endl;

  int a;
  double b;
  float c;

  test.func1(a);
  test.func1(b);
  test.func1(c);

  test.func2(a);
  // 注意调用的方法
  test.A::func2(a);

  // 先进行手动类型转换再调用，会调用当前类型下的同名函数
  // 相当于把作用域切换到了转到的类型下
  static_cast<A>(test).func2(a);

  // 也可以直接将B的实例转为A的实例
  // 使用基类中默认的赋值运算符
  //
  // object slicing
  // 不使用指针，而是直接用基类实例存储的时候，会丢掉子类中额外的内容
  // 只保留父类的内容，因此也就无法再转回去了
  // 要格外注意object slice，因为其造成了内容的丢失
  // 可以考虑使用实现多态时指针或引用的转换方法
  A testA = test;
  testA.func2(a);

  return 0;
}
