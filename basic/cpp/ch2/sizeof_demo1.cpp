#include <iostream>

int main() {
    int a {1};

    // don't need parentheses around a variable name
    // but there's no harm in putting them in
    std::cout << "the size of a variable occupies " << sizeof a << std::endl;

    return 0;
}