#include <iostream>

// 一维数组传进去只会当指针，拿不到数组信息，下面几种定义方法其实是一样的
// 在这种情况下要谨防越界，而且不能算重载，都是一样的
// void func1(int a[3], int len);
void func1(int a[], int len);
void func1(int* a, int len);

// 和一维数组相似，第一个中括号中的尺寸信息会被忽略，只当指针
// 但是第二个中括号中的尺寸是固定的，不能传入其他长度的数组
double func2(double beans[][4], int count) {
  // 第二个维度的数组尺寸是已知的，因此可以实现以下操作
  for (int i = 0; i < count; ++i) {
    // 可以拿到数组的信息
    std::cout << std::size(beans[i]) << std::endl;
    // 因为尺寸已知，可以遍历数组
    // 外层数组不能这样遍历，因为尺寸不已知，只有在尺寸已知的情况下才能这样遍历
    for (auto v : beans[i]) {
      std::cout << v << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}

int main() {
  double beans[3][4] { { 1.0, 2.0, 3.0, 4.0}, { 5.0, 6.0, 7.0, 8.0}, { 9.0, 10.0, 11.0, 12.0} };
  func2(beans, 3);

  return 0;
}