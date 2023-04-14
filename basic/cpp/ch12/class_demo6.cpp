#include <iostream>

class Box {
private:
  double length{1.0};
  double width{1.0};
  double height{1.0};

public:
  Box *setLength(double _length) {
    this->length = _length;
    // 通过this返回当前类实例的指针
    return this;
  }

  Box *setWidth(double _width) {
    this->width = _width;
    return this;
  }

  Box *setHeight(double _height) {
    this->height = _height;
    return this;
  }

  void show() {
    std::cout << length << ", " << width << ", " << height << std::endl;
  }
};

class Box2 {
private:
  double length{1.0};
  double width{1.0};
  double height{1.0};

public:
  Box2 &setLength(double _length) {
    this->length = _length;
    // 通过this返回当前类实例的指针
    return *this;
  }

  Box2 &setWidth(double _width) {
    this->width = _width;
    return *this;
  }

  Box2 &setHeight(double _height) {
    this->height = _height;
    return *this;
  }

  void show() {
    std::cout << length << ", " << width << ", " << height << std::endl;
  }
};

int main() {
  Box b1;
  // 构成了method chaining
  b1.setLength(10.0)->setWidth(10.0)->setHeight(10.0);
  b1.show();

  // 更推荐使用引用的方法，更加简洁
  Box2 b2;
  b2.setLength(10.0).setWidth(10.0).setHeight(10.0);
  b2.show();

  return 0;
}
