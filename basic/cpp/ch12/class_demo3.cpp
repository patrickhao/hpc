#include <iostream>

class Box {
private:
  double side;

public:
  // 带有单个参数的类构造函数的一个问题是，编译器可以将这样的构造函数作为从参数类型到类类型的隐式转换
  // 以下面的代码为例，当hasLargerVolumeThan函数只传入一个double时，由于Cube的构造函数只有一个double
  // 编译器可能会进行隐式转换，将double转成Cube
  Box(double side);

  // 为了避免上述问题，可以对代码进行如下转换
  // 编译器不会用加了explicit的构造函数进行隐式转换，加了explicit的构造函数只能在程序中被显示的调用
  // 注意在只有单个参数的构造器才需要注意这个
  // 隐式转换会造成许多奇奇怪怪的bug
  // 因此对于只有单个参数的构造函数或者除了第一个参数，后面的参数都有初始值的时候，最好都加上explicit，除非需要利用该隐式转换
  /* explicit Box(double side); */

  // 不只有只有单个参数的构造器才需要注意这个，多个参数也可能发生隐式转换
  // 对于有多个参数的情况也可以加上explicit
  // {1, 2, 3}与Box{1, 2, 3}可能发生转换

  double getVolume();

  bool hasLargerVolumeThan(Box box);
};

int main() {
  Box box{10.0};

  // 因为Cube的构造函数中只有一个double，编译器可能会将double隐式转化为Cube
  // 最终Constructor called被输出了两次
  // 相当于下面的代码
  // box.hasLargerVolumeThan(Box{50.0})
  if (box.hasLargerVolumeThan(50.0)) {
    std::cout << "bigger" << std::endl;
  } else {
    std::cout << "bigger" << std::endl;
  }

  return 0;
}

Box::Box(double _side) : side(_side) {
  std::cout << "Constructor called" << std::endl;
}

double Box::getVolume() { return side * side * side; }

bool Box::hasLargerVolumeThan(Box box) { return getVolume() > box.getVolume(); }
