#include <iostream>
#include <string>
#include <string_view>

// creating a string_view never involves copying any characters.
// Not even when created from a string literal.
// All it uses internally is a copy of the string’s length and a pointer to some
// external character sequence. always use the type std::string_view instead of
// const std::string& for input string parameters
// 其不关心指向数据的类型，都不会产生拷贝，注意其值是const的，不允许修改

void getStr(std::string_view str) {
  // 不允许将std::string_view转成std::string，因为使用std::string_view的目的就是避免拷贝，转换过程中又发生了拷贝
  // 但是可以用static_cast<std::string>()或者string s{str}，即新建一个string变量
  // std::string s = str;
  std::cout << str.size() << std::endl;

  // 与string的不同
  // string_view does not provide a c_str() function to convert it to a const
  // char* array it does share with std::string its data() function, though,
  // which for most intents and purposes is equivalent. string_views cannot be
  // concatenated using the addition operator (+). to use a string_view value
  // my_view in a concatenation expression, you have to convert it to a
  // std::string first, for instance using std::string{my_view}.
}

int main() {
  // char[]也不会拷贝
  getStr("123");
  return 0;
}
