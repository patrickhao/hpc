#include <iostream>

// 这个代码有问题，因为返回的是a和b的地址
// 但是a和b是largerWrong函数私有的变量，函数执行完毕后会销毁该空间
// 在返回指针时要格外注意返回值的作用域，不能返回函数作用域内变量的指针
int* largerWrong(int a, int b) {
  if (a > b) return &a;
  else return &a;
}

// 下面是上面代码的正确实现
int* larger(int* a, int* b) {
  if (*a > *b) return a;
  else return b;
}

// 如果输入的指针是const的，那么返回的指针也必须是const的
const int* larger(const int* a, const int* b) {
  if (*a > *b) return a;
  else return b;
}

// 可以通过指针返回数组
double* shiftRange(double data[], size_t count, double delta) {
  for (size_t i {}; i < count; ++i) {
    data[i] += delta;
  }

  return data;
}

// 返回引用是唯一一种可以将函数作为左值的方法
// 并且在返回引用时也要注意变量的作用域，与指针类似
std::string& largerStr(std::string& s1, std::string& s2) {
  return s1 > s2 ? s1 : s2;
}

// The program name used to invoke the program is normally recorded in the first element of argv, argv[0].
// The last element in argv (argv[argc]) is always nullptr, so the number of elements in argv will be argc + 1
int main(int argc, char* argv[]) {
  if (argv[argc] == nullptr) {
    std::cout << "the number of elements in argv will be argc + 1" << std::endl;
  }

  std::string str1 {"abcx"};
  std::string str2 {"abcf"};
  // 返回引用时可以将函数作为左值
  // 因为下面函数的string不是const的，因此不能使用string literals，string literals都是const的
  largerStr(str1, str2) = "defg";

  return 0;
}
