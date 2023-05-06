#include <iostream>
#include <string>

class Box {
protected:
  double length{1.0};
  double width{1.0};
  double height{1.0};

  double volumn() { return length * width * height; }

public:
  Box() = default;
  Box(double l, double w, double h) : length{l}, width{w}, height{h} {}
};

class Carton : private Box {
private:
  std::string material;

public:
  explicit Carton(std::string_view m = "Cardboard") : material{m} {}

  // 在通过继承访问权限控制符控制基类中成员在派生类中访问权限时，可以使用using将部分权限设置为基类中的权限，而其他的遵循继承访问权限控制的规则
  // 相当于重载了访问权限控制符，将继承控制中的private声明到了public下，变成了自己的public成员函数
  // 只需要函数名，不需要参数和返回值
  // 可以通过using将基类中的public或protected函数放宽到public，但是不能将private放宽，因为private成员在派生类中无法访问
  // 因此综上所述，只能放宽派生类能访问的成员
  // 注意这里能通过这种这种方法放宽基类中protected成员的访问权限
  using Box::volumn;
};

int main() {
  Box b;

  // 不允许，因为Box的volumn()是protected的，只能派生类能访问
  /* std::cout << b.volumn() << std::endl; */

  Carton c;
  std::cout << c.volumn() << std::endl;

  return 0;
}
