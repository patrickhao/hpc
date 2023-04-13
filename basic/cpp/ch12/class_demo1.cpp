#include <iostream>

class Box {
private:
  double length{1.0};
  double width{1.0};
  double height{1.0};

public:
  Box() {
    // 声明成员时的初始化在构造函数之前
    std::cout << length << std::endl;
    std::cout << width << std::endl;
    std::cout << height << std::endl;
  }
};

int main() {
  Box box;
  return 0;
}
