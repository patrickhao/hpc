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
    } catch (const MoreTrouble &t) {
      std::cout << "do something in inner try-catch" << std::endl;
      // 通过throw可以直接抛出当前捕获的异常，不复制
      // 但是不能在被统一层次的catch捕获，只能被上层的catch捕获
      throw;
    } catch (const Trouble &t) {
      std::cout << "can't be catched here" << std::endl;
    }
  } catch (const Trouble &t) {
    std::cout << "do something in outter try-catch" << std::endl;
  }

  return 0;
}
