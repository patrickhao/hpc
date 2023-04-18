#include <iostream>

class Box {
private:
  double x, y, z;
  // 这里只考虑了增加，没有考虑减少，是不完备的，需要在析构函数中减少count，这里只做简单的演示
  // 每个类的实例都有其自己的拷贝，static成员全局只有一个实例，静态成员也有访问控制
  // 当需要在类内部初始化static成员时，需要加上inline，inline为内联函数，用来解决频繁的函数调用产生的开销，会在调用出做一个代码替换
  static inline size_t count{};

public:
  Box(double _x, double _y, double _z) : x{_x}, y{_y}, z{_z} { count++; }

  // delegate初始化不增加count，否则会导致两次重复的增加
  Box(double a) : Box{a, a, a} {}

  Box() { count++; }

  int getCount() const { return count; }

  // 因此const成员函数能够修改非const的static变量，因为这不违背const函数不能修改实例中变量的规则，static变量本就不属于实例
  void resetCount() const { count = 0; }
};

class Box1 {
private:
  double x{}, y{}, z{};
};

class Box2 {
private:
  double x{}, y{}, z{};
  // 对实例的sizeof没有变化，因为static变量不属于任何实例

public:
  static inline size_t count{};
};

class Box3 {
private:
  double x{}, y{}, z{};

public:
  // const和static不冲突，且这几个关键字可以以任意顺序出现
  static inline const double pi{3.14};
  // 感觉这样写更正常
  /* const static inline double pi{3.14}; */
};

class Box4 {
private:
  double x{}, y{}, z{};

public:
  // static成员不属于类的实例，因此其类型可以是类本身
  const static Box4 standard_box;
};

// 没有加上inline的声明方式，在类外通过Box4指定到变量
// 这里的第一个Box4表示standard_box的类型，第二个Box4用来指定到standard_box
const Box4 Box4::standard_box{};

int main() {
  Box b1{};
  Box b2{1};
  Box b3{1, 2, 3};

  std::cout << b1.getCount() << std::endl;

  // 即使没有类的实例被创建，成员变量也存在
  // 成员变量在没有实例创建时就有了，因此可以通过以下方式访问
  // 更推荐的方式，使得代码可读性更强
  std::cout << Box2::count << std::endl;

  Box1 s1;
  Box2 s2;
  std::cout << sizeof(s1) << std::endl;
  std::cout << sizeof(s2) << std::endl;

  return 0;
}
