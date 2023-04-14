#include <iostream>

class Box {
private:
  int x, y, z;

public:
  // 编译器会默认创建一个用于copy的构造函数，如果这里是传值会于编译器默认的冲突
  // 在编译器已有默认的情况下，最好使用编译器默认的而不是自己写
  // 这里好像没有作用域的影响了
  Box(const Box &box) : x{box.x}, y{box.y}, z{box.z} {}

  // 编译器默认会为每个类都创造一个构造函数，但是当不需要时，可以加上delete删除
  /* Box(const Box &box) = delete; */
};

int main() { return 0; }
