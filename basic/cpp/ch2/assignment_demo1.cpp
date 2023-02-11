#include <iostream>

int main() {
    int a {}, b {}, c {5}, d {4};

    // you can assign a value to more than one variable in a single statement
    // you can have as many repeated assignmentes like this as you want
    a = b = c * c - d * d;

    std::cout << a << std::endl;
    
    return 0;
}