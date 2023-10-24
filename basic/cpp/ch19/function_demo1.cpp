// Using the std::function<> template
#include <cmath> // for std::abs()
#include <functional>
#include <iostream>

// A global less() function
bool less(int x, int y) { return x < y; }

int main() {
  int a{18}, b{8};
  std::cout << std::boolalpha; // Print true/false rather than 1/0

  // std::function<>能存储和函数有关的实体，例如函数指针，函数成员或者lambda表达式
  // 对于std::function<>能存储的对象的限制，必须有相同的返回值类型和参数列表
  // 参数列表可以转为int的也能存储，例如double等
  // 返回值类型不能省略，参数列表类型也不能省略
  std::function<bool(int, int)> compare;

  compare = less; // Store a function pointer into compare
  std::cout << a << " < " << b << ": " << compare(a, b) << std::endl;

  compare = std::greater<>{}; // Store a function object into compare
  std::cout << a << " > " << b << ": " << compare(a, b) << std::endl;

  int n{10}; // Store a lambda closure into compare
  compare = [n](int x, int y) { return std::abs(x - n) < std::abs(y - n); };
  std::cout << a << " nearer to " << n << " than " << b << ": "
            << compare(a, b);

  // Check whether a function<> object is tied to an actual function
  std::function<void(const int &)> empty;

  // 通过判断是否为nullptr看能否调用std::function<>中间存储的实体
  if (empty) // Or, equivalently: 'if (empty != nullptr)'
  {
    std::cout << "Calling a default-constructed std::function<>?" << std::endl;
    empty(a);
  }
}