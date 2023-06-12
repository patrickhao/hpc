#include <iostream>

int main() {
  int a{};

  std::cin >> a;

  try {
    if (a > 10) {
      // 错误类型可以是基本类型也可以是一个类
      // 更推荐使用类，其中可以包含关于错误的更多信息，这里用基本类心展示发生了什么
      // 一旦抛出错误，控制权立刻被转移到try之外
      // 随后根据catch的类型被个catch捕获或没有catch捕获
      // 这里抛出一个const char*类型的异常，因为是literal
      //
      // 在抛出异常后，调用之前执行的try块中的所有对象的析构函数，销毁这些对象
      // 因此当try中创建了指针之后，不要抛出异常，会导致内存泄露
      // 指针被销毁，但是其指向的内存没有被释放，也没有指针再指向该对象，使用智能指针可以避免该问题
      //
      // 因为销毁了所有对象，因此传递给catch的是拷贝对象
      // 用作异常的对象，必须能够复制，如果复制构造函数是private/protected或被删除，那么这个对象不能用作抛出异常
      throw "a is greater than 10";
    }
  } catch (const char *message) {
    // 不论catch中是否处理该错误
    // 控制权都会被交给最后一个catch之后，即最多只有一个catch被匹配执行
    std::cout << message << std::endl;
  }

  return 0;
}
