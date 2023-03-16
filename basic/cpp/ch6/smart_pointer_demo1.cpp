#include <iostream>
#include <memory>

int main() {
    // These are referred to as raw pointers because variables of these types contain nothing more than an address
    // A smart pointer is an object that mimics a raw pointer in that it contains an address, and you can use it in the same way in many respects
    
    // A smart pointer does much more than a raw pointer, 
    // though. By far the most notable feature of a smart pointer is that you don’t have to worry about using the delete or delete[] operator to free the memory
    // It will be released automatically when it is no longer needed

    // before c++14
    std::unique_ptr<int> ptr1 {new int {123}};

    // after c++14
    std::unique_ptr<int> ptr2 {std::make_unique<int>(123)};

    return 0;
}