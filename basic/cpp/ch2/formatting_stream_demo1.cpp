#include <iostream>
#include <iomanip>

int main() {
    double a {1.23456789};
    double b {123.456789};
    double x {123456789};
    int y {123456789};

    // round(a)
    // 1.23 -> 1.2
    // 1.26 -> 1.3
    std::cout << std::setprecision(2) << a << std::endl;

    // setprecision的精度设置将保持有效，直到更改为其他值为止
    std::cout << a << std::endl;

    // this integer specifies the total number of significant digits (2 in our example)
    // counting digits both before and after the decimal point
    // the output is 123.4
    std::cout << std::setprecision(4) << b << std::endl;
    std::cout << a << std::endl;

    // another way
    std::cout.precision(3);
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    // 默认情况下，浮点数在一定情况下会使用科学计数法
    // 定点数就不会
    // 默认的浮点数计数法，保留至多6位，包括小数点前面的，并且会删除无效位
    // 下面是官方的描述
    // When floatfield is set to defaultfloat, floating-point values are written using the default notation: the representation uses as many meaningful digits as needed up to the stream’s decimal precision (precision),
    // counting both the digits before and after the decimal point (if any).
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    // 首先用fixed消除浮点数的科学计数法，只要出现了fixed，后面的都是fixed输出
    // fixed表示的即定点数计数法，现在setprecision()控制的是小数点后的位数了
    std::cout << std::fixed << a << std::endl;
    std::cout << b << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;


    return 0;
}