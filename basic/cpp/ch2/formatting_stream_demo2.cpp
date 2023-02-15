#include <iostream>
#include <iomanip>
// there are currently no compilers that support "Text formatting" by 2020 December
#include <format>

int main() {
    double a {1.23};
    int b {123};

    std::cout << std::format("Test a: {}\nTest b: {}\n", a, b);

    return 0;
}