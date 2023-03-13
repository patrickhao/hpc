#include <iostream>

int main() {
    // the range based for loop
    int arr[] {1, 2, 3, 4, 5};

    int sum {};
    for (auto v : arr) sum += v;
    std::cout << sum << std::endl;

    //A braced initializer list itself is a valid range
    sum = 0;
    for (auto v : {1, 2, 3, 4, 5}) sum += v;
    std::cout << sum << std::endl;

    return 0;
}