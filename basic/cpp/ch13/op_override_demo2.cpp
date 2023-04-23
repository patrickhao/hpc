#include <iostream>

class Box {
private:
  double length, width, height;

  double volume() const { return length * width * height; }

public:
  Box() = default;
  Box(double l, double w, double h) : length{l}, width{w}, height{h} {}
  explicit Box(double x) : Box{x, x, x} {}

  friend bool operator<(const Box &b1, const Box &b2);
  friend bool operator<(const Box &b, double v);
  friend bool operator<(double v, const Box &b);
};

bool operator<(const Box &b1, const Box &b2) {
  return b1.volume() < b2.volume();
}

bool operator<(const Box &b, double v) { return b.volume() < v; }

bool operator<(double v, const Box &b) { return v < b.volume(); }

int main() {
  Box b1{1, 2, 3}, b2{1};
  std::cout << (b1 < b2) << std::endl;
  // 无需再单独重载int类型的比较，编译器会自动将int隐式转为double
  // 适当放宽重载的类型，利用编译器的隐式转换，减少工作量
  std::cout << (b1 < 1) << std::endl;
  std::cout << (1 < b1) << std::endl;

  return 0;
}
