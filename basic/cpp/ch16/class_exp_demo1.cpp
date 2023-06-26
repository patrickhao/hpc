#include <iostream>
#include <string>
#include <string_view>

class Trouble {
private:
  std::string m_message;

public:
  explicit Trouble(std::string_view message = "There's a problom")
      : m_message{message} {
    // 为了保证异常处理类的正确，异常类自身创建和使用的时候不能抛出异常，否则这部分异常可能无法捕获
    // 如果有外层try的话能捕获该异常，但是捕获该异常类的try不能捕获，因为实际实例化异常类并抛出的过程已经不在try的内部了
    /* throw "Trouble error"; */
  }

  std::string_view what() const { return this->m_message; }
};

class MoreTrouble : public Trouble {};

void trySomething(int i) {
  if (i == 0) {
    // 这里抛出的是一个实例，这个实例是实例化出来的
    throw Trouble{};
  } else {
    throw Trouble{"Nobody knows the trouble I've seen..."};
  }
}

int main() {
  try {
    try {
      trySomething(0);
    } catch (const Trouble &t) {
      std::cout << "Exception: " << t.what() << std::endl;
    }
  } catch (const char *message) {
    std::cout << message << std::endl;
  }

  try {
    throw MoreTrouble();
  } catch (Trouble t) {
    // 引用指针和普通实例，只要可以进行转化，就能被捕获
    // 注意普通实例之间也是能被转化的，只是因为每个类型的实例只有固定大小的空间，转化过程中可能会丢失一些信息
    //
    // 如果是引用或指针，子类自身的信息还在，这里子类自身的信息已经丢失
    std::cout << "class name: " << typeid(t).name() << std::endl;
    std::cout << t.what() << std::endl;
  }

  return 0;
}
