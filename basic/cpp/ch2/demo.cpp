#include <iostream>

int main() {

    double a {1e7};

    double b {1e7};

    a += 1e-7;

    std::cout << (a == b) << std::endl;


    return 0;
}