#include <iostream>

int main() {
    std::cout << static_cast<int>('\0') << std::endl;

    char vowels1[5] {'a', 'e', 'i', 'o', 'u'}; // 仅仅是字符数组，不是c风格的字符串，因为结尾没有'\0'
    char vowels2[6] {'a', 'e', 'i', 'o', 'u'}; // 不仅是字符数组，还是c风格的字符串，因为数组长度为6，最后一个元素会被默认设为0，而'\0'的值也是0
    char vowels3[] {'a', 'e', 'i', 'o', 'u'}; // 仅仅是字符数组，编译器会默认将数组的大小设为5

    // 另一种初始化方法，其他所有元素的值都是0
    char name1[10] {"Mike"};
    // 如果让编译器自己决定，在这种情况下数组长度为5，四个字符加上最后的终止符'\0'
    char name2[] {"Mike"};

    // 输出aeiouaeiouMike，包含了其他数组的数据，这些数据可能在内存上是连续的，因此被输出了
    // 然后碰到了Mike中的终止符，停止输出
    std::cout << vowels1 << std::endl;

    // 一种循环访问字符串元素的方法
    for (int i {}; vowels2[i]; i++) {
        std::cout << vowels2[i] << std::endl;
    }

    return 0;
}