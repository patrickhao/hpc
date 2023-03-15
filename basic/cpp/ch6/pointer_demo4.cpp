#include <iostream>
#include <cstddef>

int main() {
    int arr[5] {1, 2, 3, 4, 5};

    int* ptr1 {&arr[0]};
    int* ptr2 {&arr[4]};

    auto difference = ptr2 - ptr1;
    // a platform-specific type alias for one of the signed integer types defined by the <cstddef> module
    // Depending on your target platform, std::ptrdiff_t is typically an alias for int, long, or long long
    std::ptrdiff_t d2 = ptr2 - ptr1;

    std::cout << difference << std::endl; // 4，计算的是相隔的元素而不是字节

    return 0;
}