#include <iostream>
#include <vector>

int main() {
    // A pointer can store the address of an object of a class type
    // 类型是vector<int>*
    auto* pdata {new std::vector<int> {}};

    // 两种调用成员函数的方式
    // .的优先级高于*，因此要加上括号
    (*pdata).push_back(1);
    // arrow operator or indirect member selection operator
    pdata->push_back(1);
    
    return 0;
}