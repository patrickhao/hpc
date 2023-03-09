#include <iostream>

int main() {
    int a {1};

    // 会输出1和2
    // 进入1，但是没有break，而且已经进入了这段指令，会继续往后执行直到遇到break
    switch (a) {
        case 1:
            std::cout << "1" << std::endl;
        case 2:
            std::cout << "2" << std::endl;
            break;
        default:
            break;
    }

    int b {2};

    // 会输出2
    // 进入2，然后break
    switch (b) {
        case 1:
            std::cout << "1" << std::endl;
        case 2:
            std::cout << "2" << std::endl;
            break;
        default:
            break;
    }

    return 0;
}