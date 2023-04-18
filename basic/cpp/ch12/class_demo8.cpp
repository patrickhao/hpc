#include <iostream>

class Box {
private:
  double m_value{1.0};

public:
  // 这样的实现没有getter和setter简洁和明确
  // 这种实现也无法像setter那样可以控制数据的正确性与合理性，传出来的引用使得private变量可以直接被修改
  // 破坏了private对数据的保护
  double &value() {
    std::cout << "non-const value() called" << std::endl;
    return m_value;
  }

  // 可以通过重载将非const函数变成const函数，重载过程中返回值的类型可以改变
  double value() const {
    std::cout << "const value() called" << std::endl;
    return m_value;
  }

  // 注意下面这种情况是错误的，编译器不会通过
  // 企图在const函数中返回非const的引用，会报错
  // Because these are const member functions, their implicit this pointers are
  // of type const-pointer-to-Box (const Box*), which in turn makes the Box
  // member variable names references-to-const within the scope of these member
  // function definitions. from a const member function, you can thus never
  // return a reference or a pointer to non-const parts of an object’s states
  /* double &value() const; */
};

int main() {
  Box b1;
  const Box b2;
  // 调用哪个实现取决于实例是否是const的
  std::cout << b1.value() << std::endl;
  std::cout << b2.value() << std::endl;

  // 两种取出const的方法
  // 谨慎使用，既然拿到的是一个const，说明系统设计人员不希望该实例被更改
  // 因此在去掉const之前要谨慎，得清楚去掉了会发生什么潜在的问题
  // const_cast<Type*>(expression)
  // the type of expression must be either const Type* or Type*

  const Box *b2Ptr = new Box;
  Box *b3 = const_cast<Box *>(b2Ptr);
  std::cout << b3->value() << std::endl;

  // const_cast<Type&>(expression)
  // the type of expression can be const Type&, Type, or Type&.
  Box b4 = const_cast<Box &>(b2);
  std::cout << b4.value() << std::endl;

  return 0;
}
