#include <iostream>
#include <cmath>

int main() {
    // the easiest way to obtain a floating-point value that represents either infinity or nan
    // is using the facilities of the <limits> module of the standard library
    double a{ 1.5 }, b{}, c{};
    // result is inf
    double result { a / b };

    // to check whether a given number is either infinity or nan, 
    // you should use the std::isinf() and std::isnan() functions provided by <cmath>, what to do with the Boolean-typed results
    std::cout << "result is inf: " << std::isinf(result) << std::endl;
    std::cout << "result is nan: " << std::isnan(result) << std::endl;

    std::cout << a << "/" << b << " = " << result << std::endl;
    std::cout << result << " + " << a << " = " << result + a << std::endl;
    // result is nan
    result = b / c;

    std::cout << "result is inf: " << std::isinf(result) << std::endl;
    std::cout << "result is nan: " << std::isnan(result) << std::endl;

    std::cout << b << "/" << c << " = " << result << std::endl;

    return 0;
}