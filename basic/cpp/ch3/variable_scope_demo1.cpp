#include <iostream>

int value1 {100};

int main() {
    int value1 {1};
    // 相当于对名称为空的全局命名空间中变量的访问
    std::cout << ::value1 << std::endl;
    // 直接访问，会隐藏全局全局变量value1，默认访问当前函数中的value1
    std::cout << value1 << std::endl;

    return 0;
}