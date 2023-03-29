#include <iostream>
#include <string>

// 指针和引用
// 两者甚至编译器在背后做的事都一样，指针在传递变量时需要取址，用的时候需要dereference
// 传递指针的时候指针可以为空，但是引用必须指向某个值

// 传递指针时，因为指针可能为nullptr，因此需要在使用的时候判断指针是否为空
void changeItByPointer(double* a) {
  *a = 1;
}

// 因为传递引用和传递值在函数调用的时候时一样的，用户在不知道函数定义的时候可能无法区分两者
// 因此要保持良好的代码习惯，在传递引用的时候，如果不需要修改该值就加上const
// 同时加上const使得其可以处理const类型的变量，因为const类型的变量无法给非const类型参数
// 部分代码开发规范中，如果需要改变就传递指针，如果不需要改变就是const传递引用
// 在这种规则下，引用只作为一个避免拷贝，加速运行的手段，这样功能更单一更不容易出错
void changeIdByReference(double& a) {
  a = 2;
}

// a T value can be passed to both T& and const T& references, whereas a const T value can be passed only to a const T& reference
void func1(const std::string& str) {

};

void func2(std::string& str) {

};

// 虽然参数内传递数组是直接传的指针，但是这样无法指定第一维度的大小，可以通过传递引用解决这个问题
// 关于const的使用，参考以下建议
// input parameters should usually be references-to-const. only smaller values
// most notably those of fundamental types, should be passed by value. use reference-to-non-const only for output parameters
// 注意传递引用的格式，括号是必须的，没有括号会看成double&的数组，会报错，因为这种数组是不存在的
// 只能传递长度为10的数组，可以通过其限定数组第一维度的大小
double average10(const double (&array)[10]) { 
  double sum {};
  for (size_t i {}; i < 10; ++i) {
    sum += array[i];
  }

  return sum / 10;
}

// if you pass a fixed-size array by reference, it can be used as input to operations such as sizeof(), std::size(), and range-based for loops
double average10V2(const double (&array)[10]) {
  double sum {};
  for (auto v : array) {
    sum += v;
    // 不能通过v修改array，因为传进来的array是const的
  }

  return sum / 10;
}

int main() {
  double a {};
  changeItByPointer(&a);
  std::cout << a << std::endl;
  changeIdByReference(a);
  std::cout << a << std::endl;

  const std::string str {"123"};
  func1(str);
  // 会报错，不能将const类型变量传递给非const类型参数
  // func2(str);

  return 0;
}