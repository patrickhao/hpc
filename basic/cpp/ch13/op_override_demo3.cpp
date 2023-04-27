#include <compare>
#include <iostream>

class Box {
private:
  double length, width, height;

  double volume() const { return length * width * height; }

public:
  Box() = default;
  Box(double l, double w, double h) : length{l}, width{w}, height{h} {}
  explicit Box(double x) : Box{x, x, x} {}

  std::partial_ordering operator<=>(const Box &otherBox) const {
    // 可以访问类中的私有方法
    return volume() <=> otherBox.volume();
  }

  std::partial_ordering operator<=>(double otherVolume) const {
    return volume() <=> otherVolume;
  }

  // 编译器不会根据<=>自动生成==，但是会根据==自动生成!=
  // 如果手动重载了==，编译器生成的默认实现会被删除，等价于= delete
  /* bool operator==(const Box &otherBox) const { */
  /*   return length == otherBox.length && width == otherBox.width && */
  /*          height == otherBox.height; */
  /* } */

  // 如果没有现实的定义，会有隐式的delete，即类中默认是不含该运算符的重载的，需要手动声明
  // 即编译器有default实现，但是不会默认包含该实现，需要手动指定
  // 按照变量的声明顺序逐个判断是否相等
  bool operator==(const Box &otherBox) const = default;
};

int main() {
  Box b1{1, 2, 3}, b2{1};
  // c++20中只需要重载特定的运算符，其他的编译器会自动生成合适的
  std::cout << (b1 < b2) << std::endl;
  std::cout << (b1 < 1.0) << std::endl;

  // The reason that 1.0 <= box works is that, whenever a C++20 compiler fails
  // to find a dedicated <= operator, it attempts to rewrite expressions of the
  // form x <= y to either is_lteq(x <=> y) or is_gteq(y <=> x)2, in that order
  // The expression 6.0 <= box is therefore evaluated as if by is_gteq(box
  // <=> 1.0) (notice the swapping of the operand order!).
  std::cout << (1.0 < b1) << std::endl;

  return 0;
}
