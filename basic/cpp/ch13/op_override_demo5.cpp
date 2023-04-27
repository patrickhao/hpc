#include <algorithm>
#include <iostream>

class Box {
private:
  double length, width, height;

  double volume() const { return length * width * height; }

public:
  Box() = default;
  Box(double l, double w, double h) : length{l}, width{w}, height{h} {}
  explicit Box(double x) : Box{x, x, x} {}

  Box operator+(const Box &aBox) const {
    // 传出的是拷贝，因为该对象实例是在函数中创建，不能返回其引用，否则会出问题
    return Box{std::max(length, aBox.length), std::max(width, aBox.width),
               height + aBox.height};
  }

  friend std::ostream &operator<<(std::ostream &stream, const Box &box);
};

std::ostream &operator<<(std::ostream &stream, const Box &box) {
  stream << box.length << ", " << box.width << ", " << box.height << "\n";

  return stream;
}

int main() {
  Box b1{1, 2, 3}, b2{1};

  return 0;
}
