#include <cstddef>
#include <iostream>

class ClassA {
private:
  static inline size_t count{};
  int ax, ay;

  static void resetCount() { count = 0; }

  // 类可以嵌套，对于嵌套的类由于访问权限可以不再是全局的
  // 可以依据该特征去掉一些嵌套类访问权限的控制，全部public也可以
  class ClassB {
  private:
    // 这里就可以不需要private了，因为在ClassA的private中，也只有ClassA能访问
    // 尽管嵌套类声明在ClassA中，ClassA也不能访问ClassB中的private部分

  public:
    static inline size_t count{};
    int bx, by;

    // 一个嵌套类的成员函数可以直接访问其外层类的静态成员，以及外层类定义的其他类型和枚举
    void addClassACount() {
      // 内层嵌套类可以直接拿到外层类的private变量等，无视访问符
      count++;
      // 也可以访问static函数
      resetCount();
    }

    // 下面这种是不允许的，只允许访问外部类的static成员，其他的只能通过传进成员改变
    // 因为非static成员属于实例，嵌套的内部类也没有实例化，不知道修改的是哪个实例
    /* void addClassAAx() { ax++; } */

    // 嵌套类可以通过类对象，指针或引用的方式像访问外层类的其他成员一样访问外层类的其他成员
    // 因此只能访问外部类的static成员和枚举等
    void addClassAAx(ClassA &ca) {
      // 注意对外部类的访问可以无视其访问控制符
      // 与外部类的成员有相同的访问权限
      ca.ax++;
    }
  };

public:
  // 也可以将嵌套类放在public中，这样外部也可以访问
  // 但这违背了数据封装的理念
  class ClassC {
  private:
    int cx, cy;

  public:
    ClassC(int x, int y) : cx{x}, cy{y} {}

    void printC() { std::cout << cx << ", " << cy << std::endl; }
  };

  // 嵌套类可以在类内部定义，在外部实现
  class ClassD;

  ClassD getDefaultClassD();
};

class ClassA::ClassD {
private:
  int data;

public:
  ClassD() = default;
  ClassD(int a) : data{a} {}
};

// 因为类实现在外面，因此getIterator函数也要是现在外面，并且在类的实现之后
// 因为该函数的实现需要用到类的构造函数，并注意在外部实现时需要通过类名加::指定到类
// 只有在类内部才不可以通过名字直接指定到
ClassA::ClassD getDefaultClassD() {
  ClassA::ClassD c{1};
  return c;
}

int main() {
  ClassA::ClassC c{1, 2};
  c.printC();
  return 0;
}
