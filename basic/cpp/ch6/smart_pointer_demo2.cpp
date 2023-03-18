#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<double> ptr1 {new double {999.0}};
    std::cout << *ptr1 << std::endl;
    *ptr1 = 888.0;
    std::cout << *ptr1 << std::endl;

    // std::make_shared<T>() will typically allocate only a single contiguous memory block
    // that then stores both the shared_ptr’s reference count variable and the shared T value
    // This is both faster and more economical in memory usage
    auto ptr2 {std::make_shared<double>(999.0)};

    // 可以使用其他的shared_ptr创建ptr
    // copying pdata increases the reference count
    // 同样可以使用c++20中的make_shared_default_ptr提升性能
    std::shared_ptr<double> ptr3 {ptr2};

    // 也可以复制指针
    ptr1 = ptr2;

    // c++20之后可以使用make_shared创造数组
    // 默认初始化为0
    // 编译器好像也不太支持
    // auto ptr4 {std::make_shared<int[]>(3)};


    return 0;
}