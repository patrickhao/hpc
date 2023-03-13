#include <iostream>

int main() {
    int arr[] {1, 2, 3};
    // 逗号实际上是一个二元运算符，其将两个表达式绑定成一个，注意是表达式不是statement
    // 该运算符的值是表达式的右边的运算结果
    // 可以用逗号分隔，定义多个值
    for (int i {}, sum {}; i < std::size(arr); ++i) {
        sum += arr[i];
        std::cout << sum << std::endl;
    }

    // 下面这种方法不可行
    // for (int i {}, int sum {}; i < std::size(arr); ++i) {
    //     sum += arr[i];
    //     std::cout << sum << std::endl;
    // }
    
    int i {1};
    int value1 {1};
    int value2 {1};
    int value3 {1};

    // 该运算符的值是表达式的右边的运算结果
    std::cout << (value1 += ++i, value2 += ++i, value3 += ++i) << std::endl;

    i = 1;
    value1 = 1;
    value2 = 1;
    value3 = 1;
    // 最左边的优先级最低，所以是以下形式
    std::cout << (((value1 += ++i), (value2 += ++i)), (value3 += ++i)) << std::endl;

    // 各个部分都可以使用逗号
    for (unsigned long long n {1}, sum {1}, factorial {1}; n <= 3; ++n, sum += n, factorial *= n) {
        std::cout << n << sum << factorial << std::endl;
    }



    return 0;
}