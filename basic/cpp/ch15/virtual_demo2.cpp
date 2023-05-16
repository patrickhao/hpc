#include <iostream>

class A {
public:
  virtual void func() const { std::cout << "A" << std::endl; }
};

class B : public A {
private:
  void func() const override { std::cout << "B" << std::endl; }
};

class C {
private:
  // 基类中的虚函数设置为private更好，这可以防止其被类外调用，并且派生类也可以重载其
  // 访问权限控制和重载时两个层面的概念，不要混淆理解
  // 将虚函数声明为private时更好的选择
  virtual void func() const { std::cout << "C" << std::endl; }

public:
  void showFunc() const { func(); }
};

class D : public C {
private:
  // 访问权限控制符不控制重载，在任何时候都可以重载
  // 实际上访问权限控制符控制的是静态时的访问权限
  void func() const override { std::cout << "D" << std::endl; }
};

int main() {
  const A *aPtr{};
  B b;

  aPtr = &b;
  // 如果使用基类指针调用方法，无论派生类中的访问控制符是何种，都按基类的来
  // 例如这里可以调用B中的func()方法
  // 在动态是看的是基类的访问权限控制符，派生类中虚函数的访问权限控制符控制的是静态的访问权限
  aPtr->func();

  const C *cPtr{};
  D d;

  cPtr = &d;
  cPtr->showFunc();

  return 0;
}
