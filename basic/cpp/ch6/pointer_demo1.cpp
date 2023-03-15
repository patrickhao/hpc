#include <iostream>

int main() {
    // 在定义指针的时候最好初始化，若定义时还不知道具体值，初始化为nullptr
    // 未初始化的指针相比未初始化的数据更危险
    int* ptr {}; // ptr为nullptr，值为0，不指向任何地址空间
    // int* ptr {nullptr};

    int* p1 {}, a {}; // p1是指针但是a是int
    // 上面这种定义方式更推荐分开写或者用下面这种更清晰的写法
    int *p2 {}, aa {};

    long number {123L};
    // 取址运算符
    long* pnumber {&number};
    // 指针也可以auto
    auto pnumber2 {&number};
    // 更推荐这种写法，表示声明的是一个指针，auto*只能被初始化为指针变量
    auto* pnumber3 {&number};

    // dereference pointer
    std::cout << *pnumber << std::endl;

    return 0;
}