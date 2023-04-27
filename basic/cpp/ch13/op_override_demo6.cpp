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

  Box &operator+=(const Box &aBox) {
    length = std::max(length, aBox.length);
    width = std::max(width, aBox.width);
    height = aBox.height;

    return *this;
  }

  // 可以借助+=实现+
  Box operator+(const Box &aBox) const {
    Box copy{*this};
    copy += aBox;
    return copy;
  }

  // 两者的不同，一个参数没有int，一个有int，而不是返回值的不同
  // 这里的返回值是为了防止i++++被成功调用
  // postfix返回的是改变前的实例
  // prefix返回的是改变后的实例
  // 为了符合原生++/--操作的定义
  Box &operator++() {
    ++length;
    ++width;
    ++height;

    return *this;
  }

  // 要先留一个copy，昨晚自增操作后，返回原来的copy供上层使用，这里也体现了为什么++i比i++更快
  // the return value for the postfix operator is sometimes declared const to
  // prevent expressions such as theObject++++ from compiling
  const Box operator++(int) {
    auto copy{*this};
    // 通常使用prefix实现postfix
    ++(*this);
    return copy;
  }
};

int main() {
  Box b1{1, 2, 3}, b2{1};

  return 0;
}
