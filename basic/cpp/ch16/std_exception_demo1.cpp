#include <iostream>
#include <stdexcept>

class Box {
private:
  double l, w, h;

public:
  Box(double _l, double _w, double _h) : l{_l}, w{_w}, h{_h} {
    if (_l <= 0.0 || _w <= 0.0 || _h <= 0.0) {
      // 对标准库中异常的使用，直接抛出即可
      // 注意选择的异常类的含义与场景的实际含义相符
      // 如果没有符合的异常类，可以继承标准库中的类，派生出相应类
      throw std::out_of_range{"Zero or negative Box dimension."};
    }
  }
};

int main() { return 0; }
