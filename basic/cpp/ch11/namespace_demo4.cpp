#include <iostream>

// 如何引用其他命名空间中的名字

// 方法一
// 违背了命名空间的初衷了，直接引入整个命名空间的名字增加了冲突的可能性
// using namespace std;

// 方法二
// 引用到特定的名称
// These declarations introduce the names cout and endl from the namespace std
// into the current scope or namespace
// One using declaration may introduce many different entities. For instance,
// the using directive for std::max introduces all possible instantiations and
// overloads of the various std::max<>() templates with a single using
// declaration.
// You cannot pick and choose which overloads of a function to import into a
// namespace; you can only import a particular name (see also the comment in the
// code). std::sqrt(), for instance, has overloads for double, float, long
// double, and various integral parameters
using std::cout;
using std::endl;

int main() {
  cout << "hello" << endl;

  return 0;
}
