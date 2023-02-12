#include <iostream>

int main() {
    int k {10};

    k = k++ + 5;

    std::cout << k << std::endl;

    return 0;
}