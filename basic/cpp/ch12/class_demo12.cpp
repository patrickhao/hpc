#include <iostream>
#include <memory>

class Box {
private:
  static inline size_t count{};

public:
  Box();

  ~Box();

  static int getCount();
};

Box::Box() {
  std::cout << "constructor" << std::endl;
  count++;
}

Box::~Box() {
  std::cout << "destructor" << std::endl;
  count--;
}

// 实现的时候不用加static
int Box::getCount() { return count; }

int main() {

  for (size_t i{}; i < 3; ++i) {
    Box b;
    // 每一个b都在一个for的代码块中被创建和销毁，其生命周期就在这个代码块中
  }

  auto bPtr{std::make_unique<Box>()};
  // 这里只会输出1，前面创建的都销毁了
  // 且由于这里时智能指针，最后会回收该空间，调用一次析构函数
  std::cout << Box::getCount() << std::endl;

  // 如果不是智能指针，其不会被自动free，知道结束都不会调用该析构函数，需要手动调用
  auto bbPtr = new Box();
  // delete的时候也会调用析构函数
  delete bbPtr;

  return 0;
}
