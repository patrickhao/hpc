#include <iostream>
#include <limits>

int main() {
    std::cout << std::numeric_limits<int>::max() << std::endl;

    // For an integer type, min() results in the true minimum, which will be a negative number for a signed integer type
    // For a floating-point type, min() returns the minimum positive value that can be stored
    std::cout << std::numeric_limits<int>::min() << std::endl;
    std::cout << std::numeric_limits<double>::min() << std::endl;

    // to get the lowest negative value a type can represent, you should use lowest() instead
    // for integer types, min() and lowest() always evaluate to the same number
    std::cout << std::numeric_limits<int>::lowest() << std::endl;
    std::cout << std::numeric_limits<double>::lowest() << std::endl;

    // The number of binary digits, or bits, for example, is returned by this expression
    // For floating-point types, you’ll get the number of bits in the mantissa
    // 下方返回的结果不包括符号位，所以是31和9
    std::cout << std::numeric_limits<int>::digits << std::endl;
    std::cout << std::numeric_limits<int>::digits10 << std::endl;

    // To obtain the special floating-point values for infinity and not-anumber (NaN)
    // you should use expressions of the following form
    // 注意这些表达式对整数类型不会被编译
    // 如果编译器使用的浮点类型不支持这些特殊值，那么它们也不可能被编译
    float positive_infinity = std::numeric_limits<float>::infinity();
    double negative_infinity = -std::numeric_limits<double>::infinity();
    long double not_a_number = std::numeric_limits<long double>::quiet_NaN();

    std::cout << positive_infinity << std::endl;

    return 0;
}