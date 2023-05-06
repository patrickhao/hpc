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

  // 参数是const的，那么该函数也得是const的，因为对const实例只能调用const方法
  /* bool operator==(const Box &otherBox) const = default; */

  // 返回值的类型可以交给编译器来推断
  // 如果指定了default的<=>，编译器也会加上默认的==，因此只要指定<=>后就可以有两者的default实现
  // 默认的实现会按照变量的声明顺序逐个比较
  // 一旦发现了不相等的值，就将该值的比较结果作为整体的结果
  auto operator<=>(const Box &otherBox) const = default;

  friend std::ostream &operator<<(std::ostream &stream, const Box &box);
};

std::ostream &operator<<(std::ostream &stream, const Box &box) {
  stream << box.length << ", " << box.width << ", " << box.height << "\n";

  return stream;
}

int main() {
  Box b1{1, 2, 3}, b2{1};
  std::cout << (b1 == b2) << std::endl;

  // 代码中的返回引用，构成一个method
  // chianing，前一个返回的stream引用作为下一个<<的输入
  std::cout << b1 << b2 << std::endl;

  return 0;
}
