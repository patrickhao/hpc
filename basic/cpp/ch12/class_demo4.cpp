#include <iostream>

class Box {
private:
  int a, b, c;
  int x;

public:
  Box() = default;
  Box(int _a, int _b, int _c) : a{_a}, b{_b}, c{_c} {
    std::cout << "constructor 1" << std::endl;
  }
  // 可以复用构造函数，避免冗余的代码
  // This is called a delegating constructor because it delegates the
  // construction work to the other constructor
  // initialization list先于构造函数执行
  // 输出是
  // constructor 1
  // constructor 2
  // 只能调用同一个类中的构造函数
  // 不允许再初始化变量，如果需要初始化，只能在函数体中
  // 如果出了构造函数还需要用手动初始化其他变量，要思考这里到底适不适合用这种方法
  // 感觉上子集构造函数更适合这种方法
  Box(int _x) : Box{_x, _x, _x} { std::cout << "constructor 2" << std::endl; }
};

int main() {
  Box box{1};
  return 0;
}
