#include <iostream>
#include <limits>

int main() {
    const double nan {std::numeric_limits<double>::quiet_NaN()};
    double i = 1.0;

    // not-a-number values are neither less than, greater than, nor equal to any other number
    // Then all of the following expressions evaluate to false
    std::cout << (i > nan) << std::endl;
    std::cout << (i < nan) << std::endl;
    std::cout << (i == nan) << std::endl;

    return 0;
}