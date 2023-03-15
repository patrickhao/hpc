#include <iostream>

int main() {
    // Constant Pointers and Pointers to Constants
    
    // 不仅指针指向的数据是const，指针本身也是const，数组中的任何东西都不能被改变了
    const char* const forever_my_favorite{ "Oliver Hardy" };

    const int value {20}; // 其地址只能给指向const int的指针
    const int* pvalue {&value}; // 但是指向const int的指针可以指向非const int的地址
    // 总的来说就是要保证const变量不能改变，非const给pvalue也不违背const变量不能改变

    // 这种奇怪的写法也合法，解读的时候从右往左读
    int const * const pvalue2 {&value};

    int data {20};
    int* const pdata {&data}; // pdata只能指向非const int

    *pdata = 25; // 允许，虽然其指向的位置不能改变，但是指向位置的值可以改变

    return 0;
}