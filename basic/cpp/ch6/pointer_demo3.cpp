#include <iostream>

int main() {
    // Constant Pointers and Pointers to Constants
    
    // 不仅指针指向的数据是const，指针本身也是const，数组中的任何东西都不能被改变了
    const char* const forever_my_favorite{ "Oliver Hardy" };


    return 0;
}