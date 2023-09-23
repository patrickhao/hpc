#include <iostream>
#include <memory>

int main() {
  std::unique_ptr<int> one = std::make_unique<int>(123);
  std::unique_ptr<int> other;

  // other = one; /* 错误，没有赋值运算符，已经被删除 */
  // yet_another = other /* 错误，拷贝构造函数已经被删除 */

  // unique_ptr是move的最多的类型
  other = std::move(one); // move赋值运算符在unique_ptr中被定义了
  std::unique_ptr<int> yet_another{std::move(other)}; // move构造函数也被定义了

  // 标准库规定在move智能指针后，必须将其原始指针设置为nullptr，这些move之后的指针也可以继续指向新的地址
  // one已经被move
  one = std::make_unique<int>(456);
  std::cout << *one << std::endl;

  return 0;
}
