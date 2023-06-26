#include <iostream>
#include <string>
#include <string_view>

class Trouble {
private:
  std::string m_message;

public:
  explicit Trouble(std::string_view message = "trouble") : m_message{message} {}

  Trouble(const Trouble &t) {
    this->m_message = t.m_message;
    std::cout << "Trouble copy constructor called" << std::endl;
  }

  virtual ~Trouble() = default;

  virtual std::string_view what() const { return this->m_message; }
};

class MoreTrouble : public Trouble {
public:
  explicit MoreTrouble(std::string_view message = "more trouble")
      : Trouble{message} {}

  MoreTrouble(const MoreTrouble &t) : Trouble{t} {
    std::cout << "MoreTrouble copy constructor called" << std::endl;
  }
};

int main() {
  try {
    try {
      throw MoreTrouble{};
    } catch (Trouble &t) {
      std::cout << "class name: " << typeid(t).name() << std::endl;
      // throw t和throw不一样
      // 前者发生了复制，相当于重新抛出一个新的异常，后者不发生复制，抛出的还是当前异常
      // 如果throw后面加上捕获到的异常，相当于重新抛出了一个新的异常，加上这里捕获到的异常时Trouble引用存储的
      // 因此在抛出新异常的时候，会调用复制构造函数，但是这里调用的是Trouble的复制构造函数，因此会导致信息的丢失
      //
      // 总是使用throw;来rethrow
      throw t;
    }
  } catch (Trouble &t) {
    std::cout << "class name: " << typeid(t).name() << std::endl;
  }

  return 0;
}
