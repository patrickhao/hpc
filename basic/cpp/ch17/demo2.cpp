#include <iostream>

// 可以指定参数，这里可以指定数组开始的下标
// 这里的参数相比于成员有所不同，因为其是常数，在编译的时候会被替换
// 因此某种意义上说其比成员更加高效
//
// template中第一个参数如果指定了默认值，后面的所有参数都要指定，不然无法确定缺省参数时，哪些使用默认值
template <typename T = int, int startIndex = 0> class Array {
public:
  void someFunc();
};

// 实现的时候，函数前必须加上typename和参数
// 为了让成员函数的实现可以匹配到成员函数的定义，同时Array<>中也要传入相应的参数，所以必须都加上，不管该函数中有没有用到
template <typename T, int startIndex> void Array<T, startIndex>::someFunc() {}

int main() {
  const int ind = 10;
  // 参数可以是表达式，但是必须是常量表达式
  // 因为生成模版时参数需要在编译时确定，所以只能是const表达式
  // 而且必须符合其类型，或者可以隐式转换为其类型，注意三元运算符
  // ->和>>也同样要注意
  Array<double, ind / 10> a;

  // 指定的Non-type参数不同，生成的类类型也不同，它们之间不能互相赋值
  // 因为每个参数都会生成一个类，所以可能会生成大量代码
  // 如果有这种需求，最好的办法是将参数移至构造函数中，这样它们之间可以互相赋值，而且参数可以改变
  Array<double, 0> a1;
  Array<double, 1> a2;
  // a1 = a2;

  // 使用默认参数还是要保留尖括号
  Array<> b1;

  // 如果第一个使用默认值，其后所有的都必须使用默认值，这与函数一样
  // Array<, 1> b2;

  Array<int> b3;
}
