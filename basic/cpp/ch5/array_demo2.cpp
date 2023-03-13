#include <iostream>
#include <array>

int main() {
    int arr[] {1, 2, 3};
    // how to get the size of array
    // after c++17
    std::cout << std::size(arr) << std::endl;

    // before c++17
    // use sizeof()
    std::cout << sizeof(arr) / sizeof(arr[0]) << std::endl;

    return 0;
}