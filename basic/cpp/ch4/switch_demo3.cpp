#include <iostream>

int main() {
    int ticket_number {2};

    switch (ticket_number) {
        case 1:
            std::cout << "first prize" << std::endl;
            break;
        case 2:
            // 一种特别的用法，共用下方的三等奖，同时该case又是特别奖
            std::cout << "special bouns prize" << std::endl;
            // c++17可以手动指定fallthrough，程序员和编译器都能理解，以防编译器警告
            [[fallthrough]];
        case 3:
            // 对于空的[[fallthrough]]不是必须的
        case 4:
            std::cout << "thrid prize" << std::endl;
            break;
        default:
            std::cout << "sorry" << std::endl;
            break;
    }

    return 0;
}