#include <iostream>
#include <array>

int main() {
    // array<T, N> N必须是常量，就和定义普通数组时一样
    // 没有初始化的时候也会有垃圾元素，这与vector等大部分标准容器不同，vector会将所有元素初始化为0
    // array<T, N>设计的初衷就是尽可能贴近原生数组
    std::array<double, 100> values1 {1.0, 2.0, 3.0}; // 后续的都是0
    std::array<double, 100> values2 {}; // 用0初始化

    // As of C++17, the compiler is capable of deducing the template arguments
    std::array values3 {1, 2, 3}; // array<int, 3>

    // 设置所有元素
    values1.fill(1.0);

    // 返回的元素类型是size_t
    std::cout << values1.size() << std::endl;

    // accessing Individual Elements
    // 这种方式不会检查下标是否合法
    std::cout << values1[0] << std::endl;
    // 这种方法会检查下标是否合法，避免非法指针访问，更加安全
    // 非法的访问会抛出std::out_of_range异常
    // 额外的安去检查可能会产生额外的开销，其他场景下和标准数组性能相差无几
    std::cout << values1.at(0) << std::endl;
    // std::cout << values1.at(1000) << std::endl;
    std::cout << values1.front() << " " << values1.back() << std::endl;

    // You can compare entire array<> containers using any of the comparison operators
    // as long as the containers are of the same size and they store elements of the same type
    // Containers are compared element by element
    std::cout << (values1 < values2) << std::endl;

    // Unlike standard arrays, you can also assign one array<> container to another
    // as long as they both store the same number of elements of the same type
    values2 = values1;
    std::cout << values2.at(0) << std::endl;


    return 0;
}