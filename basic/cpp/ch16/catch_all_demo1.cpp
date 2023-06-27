#include <iostream>
#include <string>
#include <string_view>

class Trouble {
private:
  std::string m_message;

public:
  explicit Trouble(std::string_view message = "trouble") : m_message{message} {}

  virtual ~Trouble() = default;

  virtual std::string_view what() const { return this->m_message; }
};

class MoreTrouble : public Trouble {
public:
  explicit MoreTrouble(std::string_view message = "more trouble")
      : Trouble{message} {}
};

int main() {
  try {
    try {
      throw MoreTrouble{};
    } catch (...) {
      // 可以捕获所有异常
      // 一个try-catch块的职责尽可能清晰，这样也有助于debug，catch(...)只在一些特定的场景下使用比较好
      // 例如这里的使用方法，表示捕捉到异常，但是不进行处理，rethrow给上层处理
      // 不能利用catch(...)来偷懒不进行异常处理
      // 在catch中尽可能的处理详细的错误信息并记录到日志中
      std::cout << "catch exception" << std::endl;
      throw;
    }
  } catch (const Trouble &t) {
    std::cout << "do something in outter try-catch" << std::endl;
  }

  return 0;
}
