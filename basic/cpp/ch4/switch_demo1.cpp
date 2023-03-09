#include <iostream>

int main() {
    char c {'a'};

    switch (c) {
        // 匹配的时候会做一个类型转换，转换的原理与不同类型间数据运算转换的原理类似？
        // 即窄的往宽的转
        case 97:
            std::cout << 97 << std::endl;
            break;
        default:
            break;
    }

    return 0;
}