#include <iostream>
#include <string>

class Box {
private:
  int length{1}, width{1}, height{1};

public:
  Box() = default;
  Box(int l, int w, int h) : length{l}, width{w}, height{h} {}

  // copy constructor
  Box(const Box &b) : length{b.length}, width{b.width}, height{b.height} {
    std::cout << "Box(const Box &b)" << std::endl;
  }

  int volumn() { return length * width * height; }
};

class Carton : public Box {
private:
  std::string material;

public:
  Carton() = default;

  Carton(int l, int w, int h, std::string m) : Box{l, w, h}, material{m} {}

  // copy constructor
  Carton(const Carton &carton) : material{carton.material} {
    std::cout << "Carton(const Carton &carton)" << std::endl;
  }

  std::string getMaterial() { return material; }
};

class Carton2 : public Box {
private:
  std::string material;

public:
  Carton2() = default;

  Carton2(int l, int w, int h, std::string m) : Box{l, w, h}, material{m} {}

  // copy constructor
  // 可以显示调用，carton是Carton类，同时也可以转为Box类
  // 传入的是Box&类型，编译器会做类型转换匹配Box类copy构造函数的类型
  // 先调用Box的copy构造函数再调用Carton的
  Carton2(const Carton2 &carton) : Box{carton}, material{carton.material} {
    std::cout << "Carton2(const Carton &carton)" << std::endl;
  }

  std::string getMaterial() { return material; }
};

int main() {
  Carton c{1, 2, 3, "test"};

  // 这里只调用了Carton的copy构造函数，没有调用基类Box的
  // 如果不显示调用不会调用父类的copy构造函数，只会调用父类默认的构造函数创建默认的父类
  Carton c_copy{c};

  std::cout << c_copy.volumn() << std::endl;
  std::cout << c_copy.getMaterial() << std::endl;

  Carton2 c2{1, 2, 3, "test"};

  Carton2 c2_copy{c2};

  // 现在的volumn也和c2一致了，说明长宽高也拷贝过来了
  std::cout << c2_copy.volumn() << std::endl;
  std::cout << c2_copy.getMaterial() << std::endl;

  return 0;
}
