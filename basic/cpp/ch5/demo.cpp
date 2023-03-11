#include <iostream>

int main() {
    int arr[3] {1, arr[0]};
    std::cout << arr[1] << std::endl;

    return 0;
} 