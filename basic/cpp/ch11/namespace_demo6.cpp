#include <iostream>

namespace a::b::c::d {
void func() { std::cout << "func" << std::endl; }
} // namespace a::b::c::d

// 可以给变量命名空间取别名，避免超长的空间引用
namespace e = a::b::c::d;

int main() {
  e::func();
  return 0;
}
