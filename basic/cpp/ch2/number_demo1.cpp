#include <iostream>
#include <numbers>

int main() {
    // c++20 provide <numbers>, a module that defines this and several other common mathematical constants
    // g++ -std=c++20 number_demo1.cpp 
    double pi {std::numbers::pi};

    std::cout << pi << std::endl;

    return 0;
}