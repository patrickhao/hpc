#include <iostream>

// A const parameter is only distinguished from a non-const parameter for references and pointers.
// For a fundamental type such as int, for example, const int is identical to int

// 下面两种函数定义其实是一样的，不算重载，都是传入拷贝，本质上没有区别，无法通过函数调用区分二者
// 可以借助这种特征，在函数实现时加上const防止传入参数被修改，即使函数定义处没有const
long larger(long a, long b);
// long larger(const long a, const long b);


// 但是对于指针和引用而言，const long*和long*指向的就是完全不同的两个参数，可以通过调用区分二者
long larger(long* a, long* b);
const long* larger(const long* a, const long* b);

// const long&和long &也是不同的参数
long& larger(long& a, long& b);
long larger(const long& a, const long& b);

// 下面两组重载也是一样的，原因同上
long* larger2(long* a, long* b);
long* larger2(long* const a, long* const b);

long* larger2(const long* a, const long* b);
long* larger2(const long* const a, const long* const b);

// 对于参数默认值的情况，重载的时候不能有默认值，因为编译器无法知道调用哪个实现

int main() {

}

long larger(const long a, const long b) {
  return a > b ? a : b;
}