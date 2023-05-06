#include <cstring>
#include <iostream>

class Message {
private:
  char *text;

public:
  explicit Message(const char *_text = "")
      : text{new char[std::strlen(_text) + 1]} {
    std::strcpy(text, _text);
  }

  ~Message() { delete[] text; }

  const char *getText() const { return text; }

  // 编译器也生成了默认的赋值运算符，赋值运算符按照变量声明顺序逐个赋值
  // 赋值运算符也必须是成员函数
  //
  // 默认的赋值函数复制的是指针地址，而不是指针指向内存的内容
  // 这里如果其中一个实例生命周期终止，调用析构函数释放指针所指向地址空间，另一个指针指向的空间会出问题
  //
  // 参数和返回值必须都是引用，返回值是非const引用，参数是const引用
  // 链式赋值时需要用到引用的返回值
  // 返回的值和输入的值是一个类型，构成method chaining
  //
  // 默认的copy构造函数还是会出现问题，复制后两个指针指向的还是同一个地址
  //
  //
  // 因此这里和重载会不一样，在实现赋值的时候，最好也实现赋值构造函数
  Message &operator=(const Message &message) {
    // 为了防止自己赋值给自己出现问题
    // 单独判断，防止自己拷贝给自己时产生的bug
    if (&message != this) {
      delete[] text;
      text = new char[std::strlen(message.text) + 1];
    }

    return *this;
  }

  // 某些情况下可以删除重载的运算符，例如需要实现单例模式的地方
  /* Message &operator=(const Message &message) = delete; */
};

int main() {
  Message m1{"123"};

  // 这里的m2是新定义的，因此还是调用的copy构造函数
  // 注意这里的copy构造函数没有重载，还是赋值的指针地址，会出现问题
  Message m2 = m1;

  Message m3{"456"};

  // 只有在给之前已经定义的变量赋值时才会调用重载的赋值运算符
  m3 = m1;

  return 0;
}
