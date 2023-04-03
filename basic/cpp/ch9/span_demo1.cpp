#include <iostream>
#include <span>
#include <vector>
// 更通用的方式是使用函数模版，但是对于一些特定的序列数据，可以使用span
// 可以传入任何类型为int的array，vector，int[]
// 其与string_view一样，都不会进行值拷贝，都是高效的,且对c-style的数组支持更好
int largest(std::span<int> data) {
  int mx{data[0]};
  for (auto v : data) {
    if (mx < v)
      mx = v;
  }
  return mx;
}

// 可以指定span长度
double average10(std::span<const double, 10> values);

int main() {
  int a[] = {1, 2, 3};

  std::cout << largest(std::span<int>{a, 3}) << std::endl;
  // 可以省略std::span<int>，编译器会自动推断类型
  std::cout << largest({a, 3}) << std::endl;
  // 长度已知，可以省略长度
  // 当使用T的时候，编译器无法推断size时，需要手动传入size，因为T所占的byte未知，无法得到size
  std::cout << largest(a) << std::endl;

  std::vector<int> b{1, 2, 3};
  // vector也可以传
  std::cout << largest(b) << std::endl;

  // 与string_view的不同，允许值的改变，但是只能改变值，不能加入或移除元素
  std::vector<int> c{1, 2, 3};
  std::span<int> s_c(c);
  // 返回的是T&
  s_c.front() = 10;
  s_c[2] = 20;
  std::cout << c[0] << ", " << c[1] << ", " << c[2] << std::endl;

  // 因为其能修改值，因此其不允许创建const的span
  // 下面的代码是不允许的，会报错
  const std::vector<double> my_const_vector{4, 8, 15, 16, 23, 42};
  /* std::span<double> my_span(my_const_vector); */
  // 可以通过将double替换成const double，创建const的span
  // 不管传入的是不是const vector，返回的都是const T&，都不允许改变，const
  // T的别名
  std::span<const double> my_span(my_const_vector);

  // a std::string_view is thus most similar to a std::span<const char>. the key
  // difference of course is that std::string_view offers extra member functions
  // tailored to working with strings.

  // use span<const T> instead of const
  // vector<T>&. similarly, use span<T> instead of vector<T>&, unless you need
  // to insert or remove elements.

  // use span<T,N> instead of array<T,N>& or T(&)[N], and span<const T,N>
  // instead of const array<T,N>& or const T(&)[N].

  return 0;
}
