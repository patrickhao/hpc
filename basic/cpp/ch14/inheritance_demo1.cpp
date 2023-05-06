#include <iostream>
#include <string>

class Box {
protected:
  // 如果是private的属性，基类中的private成员对于Carton来说仍然是不可见的
  // 成员属性还是尽可能使用private，这里只是一个例子，展示可以这样做
  //
  // 类外部不能访问protected的属性（除friend外），但是派生类可以访问
  // 通过设计合理的多态机制来控制类之间的属性访问权限
  double length{1.0};
  double width{1.0};
  double height{1.0};

public:
  Box() = default;
  Box(double l, double w, double h) : length{l}, width{w}, height{h} {}
};

class Carton : public Box {
private:
  std::string material;

public:
  explicit Carton(std::string_view m = "Cardboard") : material{m} {}

  double cartonVolumn() { return length * width * height; }
};

int main() { return 0; }
