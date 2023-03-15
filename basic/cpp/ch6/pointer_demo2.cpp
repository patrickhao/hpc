#include <iostream>

int main() {
    /*
        下面的代码是有问题的，c风格中的字符数组是常量，不能被改变，下面的指针没有体现出这点
        这里不报错是由于历史原因，有大量不正确的赋值已经被使用，c++也只能遵循c的思路来
        对pproverb指向的内存的数据进行修改可能会报错，或者不报错但是压根没改变
    */
    // char* pproverb {"A miss is as good as a mile"};

    // gcc报segmentation fault
    // *pproverb = 'x';

    // 推荐的写法
    // 这表示指针指向的值是const的，不能被改变
    // 而不是指针本身是const的，指针本身指向的地址是可以被改变的
    const char* pproverb {"A miss is as good as a mile"};

    // *pproverb只会输出'A'
    std::cout << pproverb << std::endl;

    // 只是改变了指针指向的值，内存上的数据并没有改变，这也是不允许改变的
    char c {'B'};
    pproverb = &c;
    std::cout << *pproverb << std::endl;

    return 0;
}