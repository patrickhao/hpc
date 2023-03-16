#include <iostream>

int main() {
    double* pvalue1 {nullptr};
    pvalue1 = new double {3.14};

    double* pvalue2 {new double {3.14}}; // Pointer initialized with address in the free store

    // When you no longer need a dynamically allocated variable
    // you free the memory that it occupies using the delete operator

    std::cout << pvalue1 << std::endl;

    // 删除前无需判断是否为空，delete nullptr是无害的
    delete pvalue1; // Release memory pointed to by pvalue
    // delete只是释放了当前的内存空间，并不会清空指针指向的值，指针仍指向原来的地址空间，指针指向的当前地址可能是free的或者被立马分给了其他变量
    std::cout << pvalue1 << std::endl;

    // 对这种指针进行dereference是十分危险的，应该保持好习惯，总是将指向空间delete的指针赋为nullptr
    // 在大型项目中可能多个指针指向同一个地址，那么在这样的情况下delete指针后设为nullptr就变的非常困难
    // 具体还是要遵循一些好的代码习惯和规范
    // nullptr不能用来访问内存和释放，也不能dereference
    pvalue1 = nullptr;

    // 动态分配数组
    double* data1 {new double[10]};
    double* data2 {new double[100] {1.0, 2.0, 3.0}};

    // 也可以交给编译器自动推断数组大小
    // c++20支持，更早的编译器可能会报错
    // double* data3 {new double[] {1.0, 2.0, 3.0}};

    // delete数组，和delete普通数据不一样，这个是一下子delete该数组的所有空间
    // 并不需要指定维度，加上中括号即可
    // 多维数组也是delete []
    delete [] data1;
    // 重设指针，保持好习惯
    data1 = nullptr;

    // 多维数组
    // c++标准并不支持动态的多为数组，仅支持第一个维度是变化的，后面的是固定的
    // 下面的这种写法是有问题的
    // double **dData1 {new double[2][2] {}};
    // 这种写法才对，一个长度为10的数组，里面的元素都是double指针，复杂的句子从右往左读
    double (*dData1)[10] {new double [2][10]}; // 变量名不支持数组开头可能和这里也有关系，*2dData1可能会将*理解成乘法

    int a {};
    std::cin >> a;
    double (*dData2)[10] {new double [a][10] {}};

    delete[] dData1; // delete时同一维数组

    // 也可以将类型推断交给auto
    auto myCarrots{ new double[a][4] {} };

    // 通过一维指针数组来动态分配二维数组
    int rows {}, columns {};
    double** carrots{ new double*[rows] {} };
    for (size_t i = 0; i < rows; ++i) {
        // 注意，这样分配的数组可能并不是连续的，这并不是一种很好的方法，无法通过i * columns + j访问所有元素
        // 并且在访问连续内存空间时由于cache的优化程序会快得多
        carrots[i] = new double[columns] {};
    }
    for (size_t i = 0; i < rows; ++i) {
        delete[] carrots[i];
    }
    delete[] carrots;

    return 0;
}
