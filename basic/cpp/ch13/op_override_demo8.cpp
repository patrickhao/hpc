#include <iostream>

class ComputeVolume {
public:
  // 一般来说函数实例不会修改实例中的成员，因此一般是const的
  // 只能是成员函数，并且可以有默认参数
  double operator()(double x, double y, double z) const { return x * y * z; }

  // functor也是可以重载的
  double operator()(double x, double y) const { return x * y; }
};

class Box {
private:
  int x, y, z;

public:
  Box(int _x, int _y, int _z) : x{_x}, y{_y}, z{_z} {}

  int volumn() const { return x * y * z; }

  // 通常不会改变本类的成员，是转到目标类上去，因此是const
  // 要转成的目标变量的类型通常蕴含在变量名中，因此不需要返回值
  // 这里要注意辨别，形式上不是很好分辨这种重载
  //
  // 可以通过explict避免隐式转换，在一些情况下隐式转换可能会产生问题
  // 例如构造函数和类型转换重复的会冲突，编译器不知道该调用哪个
  // Type2(const Type1& theObject);
  // operator Type2() const;
  // 这里的函数调用形式和下方的转换调用形式一样，编译器无法决定该调用哪个
  // 两者都是Type2(type1)，注意初始化是int(1)和int{1}都是可以的
  // 加上explicit可以避免潜在发生的冲突
  //
  // 这个和()运算符一样，也只能定义为成员函数
  // 类型转换的重载也是唯一没有返回值的，该重载的返回值在operator关键字之后
  explicit operator int() const { return volumn(); }
};

int main() {
  // 有点像创造了一个函数的实例，可以将该实例的名字当成函数用
  // 是一个能存储变量的函数，更加友好的调用static和global变量
  // 比如该类可以维护自己的静态变量，统计函数调用的次数等，变量的定义更加清晰，位置更加合理
  ComputeVolume computeVolume;

  std::cout << computeVolume(1, 2, 3) << std::endl;

  // 另一种调用方式
  std::cout << computeVolume.operator()(1, 2, 3) << std::endl;

  Box b{1, 2, 3};
  /* int test{b}; */
  int test = static_cast<int>(b);
  std::cout << test << std::endl;

  return 0;
}
