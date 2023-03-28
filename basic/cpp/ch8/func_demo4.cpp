#include <iostream>

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

int main() {
  double a {};
  changeItByPointer(&a);
  std::cout << a << std::endl;
  changeIdByReference(a);
  std::cout << a << std::endl;
}