#include <iostream>

int main() {
    int k {10};

    /*
    the C++17 standard added the rule that all side effects of the right side of an assignment (including compound assignments, 
    increments, and decrements) are fully committed before evaluating the left side and the actual assignment. 
    Meaning that with C++17, our statement should take k from 10 to 15
    */
    k = k++ + 5;

    std::cout << k << std::endl;

    return 0;
}