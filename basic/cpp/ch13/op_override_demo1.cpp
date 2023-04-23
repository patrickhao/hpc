#include <iostream>
#include <sys/wait.h>

class Box {
private:
  double length, width, height;

public:
  Box() = default;
  Box(double l, double w, double h) : length{l}, width{w}, height{h} {}
  Box(double x) : Box{x, x, x} {}
  /* explicit Box(double x) : Box{x, x, x} {} */

  double volume() const { return length * width * height; }

  // 大体上重载算子的函数和之前写的一样，但是函数名不一样，函数名为operator加上要重载的算子
  // 重载的二元运算符的参数只有一个，比较的时候用的是引用，不会有额外的性能开销
  // 在类的实例为左侧的运算符时调用该重载的运算符，右侧的变量或值为重载函数的输入，this指针指向左侧的变量
  // 在重载比较两个相同的变量的运算符时要注意左右的关系
  // 或者可以通过将重载的运算符定义为非成员函数，传入所有参数区分左右
  // 当比较运算符的两侧的参数类型不同时，去左边类型的类中重载相应运算符，记住this指向左边的即可
  // 运算符重载也是函数，可以将函数的实现放在类内或者类外
  bool operator<(const Box &box) {
    // 小于就返回true，否则返回false
    return this->volume() < box.volume();
  }
};

// 也可以将算子重载定义为非成员函数
// 可以通过将函数定义为friend访问类中的私有成员和方法
bool operator<(const Box &box1, const Box box2) {
  return box1.volume() < box2.volume();
}

int main() {
  Box b1{1, 2, 3};
  Box b2{1, 1, 1};
  Box smallBox;

  if (b1 < b2) {
    // 编译器为Box生成了默认的赋值运算符重载
    smallBox = b1;
    std::cout << "b1 < b2" << std::endl;
  } else {
    smallBox = b2;
    std::cout << "b2 < b1" << std::endl;
  }

  // 另一种调用方式
  // 重载的运算符本质上也是函数，其也有函数名，并且在运算符出现时会调用该函数
  if (b1.operator<(b2)) {
    std::cout << "b1 < b2" << std::endl;
  } else {
    std::cout << "b2 < b1" << std::endl;
  }

  // 构造函数不加explicit可能会引发的问题
  // 这里隐式调用了构造函数，2实际上是Box{2}，计算出来的体积为8
  if (b1 < 2) {
    std::cout << "volume b1 < 2" << std::endl;
  } else {
    std::cout << "volume b1 > 2" << std::endl;
  }

  return 0;
}
