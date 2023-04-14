#include <iostream>

class Box {
private:
  double length, width, height;

public:
  Box(double l, double w, double h) : length{l}, width{w}, height{h} {}

  void setLength(double l) { this->length = l; }

  void setWidth(double w) { this->width = w; }

  void setHeight(double h) { this->height = h; }

  double getLength() { return this->length; }

  double getWidth() { return this->width; }

  double getHeight() { return this->height; }

  double getVolume() { return getLength() * getWidth() * getHeight(); }
};

class Box2 {
private:
  double length, width, height;

public:
  Box2(double l, double w, double h) : length{l}, width{w}, height{h} {}

  void setLength(double l) { this->length = l; }

  void setWidth(double w) { this->width = w; }

  void setHeight(double h) { this->height = h; }

  // 对于没有修改属性的函数在最后加上const，若定义与实现分开，实现后迷啊也要加上const
  // this指针也变成了const Box2*
  double getLength() const { return this->length; }

  double getWidth() const { return this->width; }

  double getHeight() const { return this->height; }

  // 加上const后编译器会检查函数有没有改变属性，若改变了会报错，
  // 因此可能编译器只会对加上const的函数进行检查，对于没有加上const的函数，一律不允许调用，也就不会耗费额外的开销进行检查了
  // const函数内也只允许调用const函数，调用非const函数会报错
  double getVolume() const { return getLength() * getWidth() * getHeight(); }
};

int main() {
  const Box box{1, 2, 3};

  // 下面的代码是不允许的
  // 加上const后无法修改属性，指向const变量的指针也无法修改
  // 加上const之后，编译器不允许直接修改成员，也不允许间接的修改，因此所有的setter都不允许被调用
  /* box.setLength(3); */

  // 为了防止getter中对成员潜在的修改，getter也不允许被调用
  // 因此只允许调用加了const的函数
  // 编译器不会去推断函数中具体在做什么，有没有修改属性，没有加const的一律不能调用
  // 加了const可以调用，但是会检查是否修改属性，如果修改会报错
  /* box.getLength(); */

  const Box2 box2{1, 2, 3};

  // const实例可以调用const方法
  std::cout << box2.getVolume() << std::endl;

  return 0;
}
