#include <cstddef>
#include <iostream>

class Box {
private:
  double x, y, z;
  static inline size_t count{};

public:
  Box(double a, double b, double c) : x{a}, y{b}, z{c} { count++; }
  Box(double a) : Box{a, a, a} {}

  // 可以用static函数来操作static变量，而不用关心实例是否创建
  // 如果一个函数不涉及任何非static变量时，其就可以被声明为static函数
  static size_t getCount() { return count; }

  // static函数不能直接访问类实例中的所有变量，只能通过参数传进去，静态函数应该和静态变量一样，放在别的地方，没法访问实例的变量
  // 因为static函数也是类中的成员，因此其可以访问类成员中的所有变量，不论是private还是public的，对于访问控制，其和正常的函数一样
  // 这里和friend函数有点相似，类的实例只能通过参数传入
  static double getVolumn(const Box &box) { return box.x * box.y * box.z; }

  // static函数不能是const，因为其与任何实例无关，也没有this指针，因此实例的const与否与其也没有关系，其不能为const
};

int main() {
  Box b1{1, 2, 3};
  Box b2{1};

  // 调用static函数的方式
  std::cout << Box::getCount() << std::endl;
  // 不推荐通过类实例来调用staitc函数，更推荐上一种
  std::cout << b1.getCount() << std::endl;

  std::cout << Box::getVolumn(b1) << std::endl;
  std::cout << b1.getVolumn(b1) << std::endl;

  return 0;
}
