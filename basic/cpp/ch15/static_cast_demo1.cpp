#include <iostream>

class A {
protected:
  int x;
};

class B : public A {
protected:
  int y{10};

public:
  void func() const { std::cout << y << std::endl; }
};

int main() {

  const A *aPtr1{new A};
  const A *aPtr2{new B};

  // 这里存储的是A的实例，没有B中的信息，因此虽然不会报错，但是强行转过去部分属性的值会出问题
  // 转换是否成功取决于指针指向的实例是何种类型，如果其是需要转换的类型或其派生类，其中有相关信息，那么就可以转，否则就不合法
  // 静态转换不会做这种类型检查，因此可能会出现未定义的错误
  const B *bPtr1 = static_cast<const B *>(aPtr1);
  const B *bPtr2 = static_cast<const B *>(aPtr2);

  bPtr1->func();
  bPtr2->func();

  return 0;
}
