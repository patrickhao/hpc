#include <iostream>
#include <memory>

int main() {
    // These are referred to as raw pointers because variables of these types contain nothing more than an address
    // A smart pointer is an object that mimics a raw pointer in that it contains an address, and you can use it in the same way in many respects
    
    // A smart pointer does much more than a raw pointer, 
    // though. By far the most notable feature of a smart pointer is that you don’t have to worry about using the delete or delete[] operator to free the memory
    // It will be released automatically when it is no longer needed

    // before c++14
    std::unique_ptr<int> ptr1 {new int {123}};

    // after c++14
    std::unique_ptr<int> ptr2 {std::make_unique<int>(123)};

    // 可以将类型推断交给编译器
    auto ptr3 {std::make_unique<int>(123)};

    // 可以像正常指针一样使用智能指针
    *ptr1 = 456;
    std::cout << *ptr1 << std::endl;

    // 可以使用get()得到指针的地址
    // 不建议复制该地址到raw pointer中，因为这样又要自己管理内存了
    std::cout << ptr1.get() << std::endl;

    // 创建数组，括号内的数是数组的长度
    std::unique_ptr<double[]> ptra1 {std::make_unique<double[]>(3)}; // 长度为3的double数组

    for (int i {}; i < 3; ++i) {
        ptra1[i] = static_cast<double>(i);
    }

    // 关于初始化，make_unique<>会对所有基础类型进行初始化
    std::unique_ptr<int> ptr4 {std::make_unique<int>()}; // 如果括号内没有元素，则默认初始化为0，这与普通指针是不同的
    std::unique_ptr<int[]> ptra2 {std::make_unique<int[]>(3)}; // 数组内所有的元素初始化为0
    // 但是有的时候初始化是影响性能的，在有的场景下希望不要进行初始化
    // c++20可以使用default init，即定义变量时默认的初始化类型，也就是不初始化为0，内存里是什么就是什么
    // 编译器好像还不支持，但是有这么个东西
    // std::unique_ptr<int> ptr5 {std::make_unique_default_init<int>()};
    // std::unique_ptr<int[]> ptra3 {std::make_unique_default_init<int[]>(3)}

    // 可以通过reset()重设任何智能指针，不带参数即设为nullptr
    // 因为这是一个unique_str<>，释放后没有任何指针指向该地址，该地址将会被释放
    ptr1.reset();  // 现在指向nullptr，指针指向的地址变了，但是指针这个对象还在，还可以指向其他地址
    // 这里不能像下面这么用，只能new，因为这里设置的是指针的地址，而不是智能指针对象，make_unique<>返回的是智能指针对象
    // ptr1.reset(std::make_unique<int>(3));
    // 但是可以这样用，不过这样显得很奇怪，在这种情况下类的实例没有被储存，其指向的地址是不是也会被释放
    ptr1.reset(std::make_unique<int>(3).get());

    // 这样写就好
    ptr1.reset(new int {3});

    // 可以用release()将智能指针转回普通指针，转回后需要手动释放内存
    // 尽量不用，这个可能会造成内存泄漏（如果单纯release()而没有存下其返回的指针的话）
    int* rawPtr1 = ptr1.release();

    std::cout << *rawPtr1 << std::endl;

    // The smart pointer no longer does this for you!
    delete rawPtr1;
    


    return 0;
}