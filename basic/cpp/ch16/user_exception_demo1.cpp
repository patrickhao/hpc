#include <algorithm>
#include <exception>
#include <iostream>
#include <stdexcept>

class DimensionError : public std::out_of_range {
private:
  double m_value;

public:
  // 构造函数不能加noexcpet，因为其可能在拷贝的时候可能会出现异常
  explicit DimensionError(double value)
      : std::out_of_range{"Zero or negative dimension: " +
                          std::to_string(value)},
        m_value{value} {}

  double getValue() const noexcept { return m_value; }
};

class Box {
private:
  double l, w, h;

public:
  Box(double _l, double _w, double _h) : l{_l}, w{_w}, h{_h} {
    if (_l <= 0.0 || _w <= 0.0 || _h <= 0.0) {
      throw DimensionError{std::min({_l, _w, _h})};
    }
  }

  double volume() const { return l * w * h; }
};

int main() {
  try {
    Box b1{1, 2, 3};
    std::cout << "box1 volume is " << b1.volume() << std::endl;
    Box b2{1, -2, 3};
    std::cout << "box2 volume is " << b2.volume() << std::endl;
  } catch (const std::exception &ex) {
    // 因为是继承的标准异常类，所以其也是exception的子类，可以用用一个catch捕获并处理
    std::cout << "Exception caught in main(): " << ex.what() << std::endl;
  }
}
