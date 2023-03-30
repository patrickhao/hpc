#include <iostream>
#include <string>

// 在类型确定的情况下，可以交给编译器推测类型
auto getAnswer() { return 12; }

// 多个return时若返回的值类型不同，编译器无法推断，会报错
// 不要尝试在第二个return后面加上c_str()，其会创建一个指向临时变量的指针，string并非char*，这个临时变量作用域在函数内，返回其指针会发生bug
// auto getFirstLetter(const std::string& text) { // function to get first letter, not as a char but as another string
//   if (text.empty()) return " "; // deduced type: const char* 
//   else return text.substr(0, 1); // deduced type: std::string 
// }

// 返回值类型是string，而不是string&，因为auto不会推断出引用或const
// 可以通过auto&来让编译器推断引用，通过const auto让编译器推断const，通过const auto&让编译器推断const引用
// 上述规则不仅对返回值类型的推断有用，在本地使用auto推断类型时也有用
auto larger(std::string& s1, std::string& s2) {
  return s1 > s2 ? s1 : s2;
}

int main() {
  std::string test = "123";
  const std::string& refToTest = test;
  // auto_test不是const也不是引用，就是string，拷贝了refToTest中的值
  auto autoTest = refToTest;

  return 0;
}