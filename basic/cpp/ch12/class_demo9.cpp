#include <iostream>
#include <memory>

class Box {
private:
  double length, width, height;

public:
  Box() : Box{1.0, 1.0, 1.0} {}

  Box(double l, double w, double h) : length{l}, width{w}, height{h} {}

  double volume() const { return length * width * height; }

  // 一个friend能够访问当前类的所有成员，不管其access specification
  // friend的访问权限和类内部的其他成员相同
  // friend违背了面向对象中的data hiding，因此只有在非常确定的情况下再使用
  // 可以指定类中的某个函数或者某个类作为friend
  // 一个函数不能是其所属类的友元函数，因此访问控制符不适用于类的友元函数，访问控制符没法控制不属于该类的成员
  // 因此不管放在private下面或者public下面都可以
  // 这里放在public的最后，因为逻辑上其也可以看作class的public的接口
  // 声明friend的方法，写上该函数声明，并在前面加上friend关键字
  friend double surfaceArea(const Box &box);

  // 也可以直接将类设为friend，类中的所有函数都有friend类的所有属性的访问权限
  // friend是单向的，A -> B B x A
  // 并且friend的关系不能传递 A -> B B -> C A x C
  friend class BoxTools;
};

class BoxTools {
public:
  double surfaceArea(const Box &box) {
    return 2.0 * (box.length * box.width + box.length * box.height +
                  box.height * box.width);
  }
};

int main() {
  BoxTools bt;
  Box box1;
  std::cout << surfaceArea(box1) << std::endl;
  std::cout << bt.surfaceArea(box1) << std::endl;

  auto box2{std::make_unique<Box>(1.0, 2.0, 3.0)};
  std::cout << surfaceArea(*box2) << std::endl;
  std::cout << bt.surfaceArea(*box2) << std::endl;

  return 0;
}

// 这个函数虽然不是Box类的，但是因为Box了中声明了其为friend，其能够访问Box的所有成员，无论访问控制符的类型
// 在class中可以看作已经声明了，因此在main之后实现也可以，同样的实现也可以直接放在class中，但是这样代码耦合度太高了
double surfaceArea(const Box &box) {
  return 2.0 * (box.length * box.width + box.length * box.height +
                box.height * box.width);
}
