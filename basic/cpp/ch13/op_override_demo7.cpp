#include <iostream>
#include <vector>

// 仅做演示用途，正常不会这么实现
class IntArray {
private:
  std::vector<int> data;

public:
  IntArray(std::vector<int> d) : data{d} {}

  // 对于某些含有序列成员的类，可以通过重载[]让其可以像数组一样使用
  // 注意这里尽量使用高效的实现，而不是使用遍历等低效的方式
  // 因为该运算符可能会被大量调用，关键部分的性能格外重要
  // 注意这里的返回值是拷贝，修改其值不会修改实际存储的值
  // 可以通过返回引用使得值可以被修改
  int operator[](size_t index) const { return data[index]; }

  friend std::ostream &operator<<(std::ostream &stream,
                                  const IntArray &intArrya);
};

std::ostream &operator<<(std::ostream &stream, const IntArray &intArray) {
  for (auto v : intArray.data) {
    stream << v << " ";
  }
  stream << "\n";
  return stream;
}

int main() {
  std::vector<int> a{1, 2, 3};
  IntArray ia{a};

  std::cout << ia[1] << std::endl;
  std::cout << ia << std::endl;

  return 0;
}
