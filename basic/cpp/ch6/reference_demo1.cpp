#include <iostream>

int main() {
  /*
   * 引用：某个变量的别名
   * 与指针的不同
   * 和指针不一样，不能不初始化它，因为他是别名，必须告诉它引用的是哪一个变量
   * 引用不能被更改，一旦一个引用创建，在该引用剩余的生命周期都会引用同一个变量
   * 
  */
  double data {1.23};
  // The ampersand (&) following the type name indicates that the variable being defined, rdata, is a reference to a variable of type double
  // rdata is of type reference to double
  double& rdata {data}; // Defines a reference to the variable data

  // 相比使用原来的变量名，也可以使用引用
  // 不需要dereference，直接当普通变量用即可
  rdata += 1;
  std::cout << data << std::endl;

  // 指向引用的指针都是一样的
  double* ptr1 {&data};
  double* ptr2 {&rdata};

  std::cout << (ptr1 == ptr2) << std::endl;

  double other_data {4.56};
  // 现在只会把other_data看成一个值，而不会将rdata的引用指向other_data
  // rdata是data的别名并且会永远是data的别名
  // 引用会永远等于其指向的值
  // 引用更像一个const指针，其指向的值不允许改变
  rdata = other_data;

  // const引用，不允许通过其改变其引用的值
  // 可以通过这种方式保护传出去的数据不能被修改，但是数据本身又可以修改
  // 对于一些不想让结构修改数据但是又想传递引用以加快速度的情况下，可以加上const
  const double& constRef {data};

  // 这是不允许的
  // constRef = 2.34;
  // 但是原来的数据仍然可以修改，只是不能通过引用来修改
  data = 2.34;

  std::cout << data << std::endl;
  std::cout << rdata << std::endl;

  return 0;
}