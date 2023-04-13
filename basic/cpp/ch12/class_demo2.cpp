#include <iostream>

class Box {
private:
  int length{}, width{}, height{};

public:
  // 一旦定义了构造函数，就不会在创建任何默认的构造函数
  // 这里手动指定了参数为空时的构造函数，default代表使用默认的
  Box() = default;
  // 这种方式也可以，但是modern c++更推荐上面那种
  // you should use = default; over {}. not only does this make it more apparent
  // that it concerns a default default constructor, there are also a few subtle
  // technical reasons that make the compiler-generated version the better
  // choice.
  /* Box() {} */

  Box(int _length, int _width, int _height);
};

int main() {
  // 创造类实例的方法，和其他类型变量初始化的方法一致
  Box box{1, 2, 3};
  return 0;
}

// 可以将类中函数的声明和实现分开，方法名钱加上函数名表示是哪个类的函数
// 如果初始化的变量是一个类，会调用其相应的构造函数
// 对于成员是类的实例时，这种方式是非常有效的
// 这些变量初始化的顺序与其在函数中声明的顺序相同，而不是和member initializer
// list中的相同
// 在初始化时，依赖前面已经初始化过的变量的值类初始化后面的变量时要格外注意这个顺序的问题
// 最好将所有的初始化都放在member initializer
// list或构造函数中，对于前者，最好将其顺序与函数参数列表中的顺序保持一致，而当对初始化的顺序有要求
// 例如后续的初始化需要依靠前者的值，或者设计复杂的逻辑时推荐都放在构造函数中
Box::Box(int _length, int _width, int _height)
    : length(_length), width(_width), height(_height) {}
