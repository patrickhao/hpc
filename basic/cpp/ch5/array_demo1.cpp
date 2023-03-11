#include <iostream>

int main() {
    int arr[3] {1, 2, 3}; // Define & initialize array

    int brr[3] {1}; // the last two will be 0, brr[0] = 1, brr[1] = 0, brr[2] = 0

    int crr[3] {}; // All elements 0

    int drr[3] {1, arr[0]}; // 一些奇怪的玩法，好像也没报错并且输出正常

    return 0;
}