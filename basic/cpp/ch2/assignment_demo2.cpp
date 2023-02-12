#include <iostream>

int main() {
    // op= assignment operators, the parentheses are important
    // lhs op= rhs
    // lhs = lhs op (rhs)

    int x {2}, y {3};

    // equal to x = x * (y + 1)
    x *= y + 1;

    // the output is 8, not 7
    std::cout << x << std::endl;


    return 0;
}