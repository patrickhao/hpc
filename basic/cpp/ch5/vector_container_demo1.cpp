#include <iostream>
#include <vector>

int main() {
    std::vector<int> a(10); // 默认初始化所有元素为0
    
    // 其他的几种初始化方式
    std::vector b(10, 99L);
    std::vector c {1, 2, 3}; // c++17之后可以推测类型

    std::vector numbers(20, 99L); // Vector contains 20 long values - all 99
    numbers.assign(99, 20L); // Vector contains 99 long values - all 20
    numbers.assign({99L, 20L}); // Vector contains 2 long values - 99 and 20
    numbers.clear(); // 删除所有元素

    // 会将a整个复制到c，即使长度不同
    // 这与array不同，array仅仅在长度相同时才能复制
    c = a;
    std::cout << c.size() << std::endl;
    
    // at的用法和array一样
    std::cout << a.at(0) << std::endl;

    // 不等长的两个vector也可以进行比较，采用词典法比较原则
    // 即在词典中出现在前面的小，例如在下面的例子中，d < e
    std::vector<int> d {1, 2, 3};
    std::vector<int> e {1, 2, 3, 4, 5};

    std::cout << (d < e) << std::endl;

    return 0;
}