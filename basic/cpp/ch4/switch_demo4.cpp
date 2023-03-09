#include <iostream>

int main() {
    int test {3};
    switch (test) {
        // 这部分无法达到，是非法的
        int i {1}; // ILLEGAL - cannot be reached
    case 1:
        // 虽然在这里j进行了初始化，但是j的作用域是遍布整个switch的
        // 可能在其他case访问到j但是没有初始化，这是危险的行为，下面的bypass也是同样的意思，能被访问但是初始化过程可能会跳过
        // gcc编译器报错crosses initialization
        int j {2}; // ILLEGAL - con be reached but can be bypassed
        std::cout << test + j << std::endl;
        break;

        // 在break后，同样无法到达
        int k {3}; // ILLEGAL - cannot be reached
    case 3: {
        // 使用{}围绕，将作用域限定在该case中，因此不会产生crosses initialzation问题
        int m {4}; // OK - can be reached and cannot be bypassed
        std::cout << test + m << std::endl;
        break;
    }
    default:
        // 这里default已经是最后的部分了，尽管n也能够被整个switch使用，但是定义之后也只有该case能使用了
        // 如果default后面还有case，同样会发生crossed initialzation问题
        int n {5}; // OK - can be reached and cannot be bypassed
        std::cout << test + n << std::endl;
        break;
    }

    return 0;
}