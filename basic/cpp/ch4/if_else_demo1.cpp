#include <iostream>

int main() {
    int a {10};
    int b {-10};

    // 没有括号的情况下，else会优先匹配近的if
    // 这种复杂的分支更推荐使用括号，分清层次
    if (a > 0) 
        if (b > 0)
            std::cout << "1" << std::endl;
    else
        std::cout << "2" << std::endl;


    return 0;
}