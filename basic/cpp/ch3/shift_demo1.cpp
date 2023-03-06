#include <iostream>

int main() {
    signed char positive {+104}; // 01101000
    signed char negative {-104}; // 10011000

    // 带符号的整型右移时左侧补位的是符号位，负数补的都是1，正数补的都是0
    positive >>= 2; // Result is '00'011010, or +26, which is +104 / 4
    negative >>= 2; // Result is '11'100110, or -26, which is -104 / 4

    // 左移时会直接在右侧补0，但是要注意符号位时直接丢弃的，所以没有乘2n的效果了
    positive <<= 2; // Result is 101000'00', or -96 (+104 * 4 = +416, or 01'10100000)
    negative <<= 2; // Result is 011000'00', or 96 (-104 * 4 = -416, or 10'01100000)

    return 0;
}