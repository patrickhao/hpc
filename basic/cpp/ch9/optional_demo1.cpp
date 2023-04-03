#include <iostream>
#include <optional>
#include <string>

std::optional<size_t>
findLast(const std::string &string, char target,
         std::optional<size_t> startIndex = std::nullopt) {
  // code below will not work for empty strings
  if (string.empty())
    return std::nullopt;

  // 如果startIndex是std::nullopt，那么从最末尾开始查找
  // value_or()：如果有值，就是其值，否则就是括号中的内容
  // 这样在不知道string长度的情况下也能将数组长度设为默认值
  size_t index = startIndex.value_or(string.size() - 1);

  while (true) {
    if (string[index] == target)
      return index;
    if (index == 0)
      return std::nullopt;
    --index;
  }
}

std::optional<std::string> func2(int a) {
  if (a >= 0)
    return {};
  else
    return "123";
}

int main() {
  const auto str = "Growing old is mandatory; growing up is optional.";

  const std::optional<size_t> foundA{findLast(str, 'a')};
  if (foundA) {
    std::cout << "Found the last a at index " << *foundA << std::endl;
  }

  const auto foundB{findLast(str, 'b')};

  // 如果不进行指定，编译器会将其转为bool
  if (foundB.has_value()) {
    std::cout << "Found the last b at index " << foundB.value() << std::endl;
  }

  const auto foundEarlyI{findLast(str, 'i', 10)};

  if (foundEarlyI != std::nullopt) {
    std::cout << "Found an early i at index " << foundEarlyI.value()
              << std::endl;
  }

  const std::optional<std::string> a{func2(1)};  // std::nullopt
  const std::optional<std::string> b{func2(-1)}; // "123"

  // return {} 会被编译器转成合适的格式，这里是std::nullopt
  // 对于vector<int>可能会被转成一个空的vector<int>
  if (a == std::nullopt) {
    std::cout << "turn into std::nullopt" << std::endl;
  }

  // 这里两种方式都可以调用string的方法
  // 这里存的是值的拷贝
  std::cout << (*b).size() << std::endl;
  std::cout << b->size() << std::endl;

  return 0;
}
