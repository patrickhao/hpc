#include <iostream>
#include <cctype>

int main() {
    const int max_length {100};
    char text[max_length] {};

    std::cout << "Enter a line of text:" << std::endl;

    // Read a line of characters including spaces
    // param1: where the input is to be stored
    // param2: the maximum number of characters that you want to store
    // param3(可选): specifies an alternative to '\n' to indicate the end of the input
    // 会自动在末尾加上终止符
    std::cin.getline(text, max_length, '\n');
    std::cout << "You enterd:\n" << text << std::endl;

    return 0; 
}