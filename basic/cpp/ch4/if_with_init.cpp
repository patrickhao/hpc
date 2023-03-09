#include <iostream>

int main() {
    char input {'A'};

    // 下面是一种比较常见的方式
    // 但是这种方式有问题，lower1在后续的代码中不会再出现，可以通过一些方法限制其作用域以免后续发生冲突或不必要的bug
    // llvm源码中大量的匿名命名空间可能也有这层考虑
    auto lower1 {static_cast<char>(std::tolower(input))};
    if (lower1 >= 'a' && lower1 <= 'z') {
        std::cout << "You've entered the letter '" << lower1 << "'" << std::endl;
    }
    // ... more code that does not use lower1

    // 下面是一种有效但粗糙的方法
    // 通过{}将lower2的作用域限定起来
    {
        auto lower2 {static_cast<char>(std::tolower(input))};
        if (lower2 >= 'a' && lower2 <= 'z') {
            std::cout << "You've entered the letter '" << lower2 << "'" << std::endl;
        }
    }

    // c++17提供了一种新的方法，对于if和switch都适用
    // if (initialization; condition) ...
    // switch (initialization; condition) {...}

    // initialization会先于condition执行
    if (auto lower{ static_cast<char>(std::tolower(input)) }; lower >= 'a' && lower <= 'z') { 
        std::cout << "You've entered the letter '" << lower << '\'' << std::endl; 
    } // ... more code (lower does not exist here)


    return 0;
}