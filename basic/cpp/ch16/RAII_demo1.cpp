#include <iostream>

// 使用一个实例来管理分配的对象来保证原子性，在析构函数中释放相应的资源
// 很多人忘记在return前释放资源，因此RAII时非常必要的，特别是一些人的return比较隐晦时
//
// 在导致异常并被try-catch捕获到的情况下，当控制权转移至catch块中时
// DoubleArrayRAII实例的生命周期就到头了，其析构函数会被调用，也就释放了其分配的内存空间
// 如果没有异常处理，整个程序都会停止，所以该类的功能是建立在有异常处理的情况下
// std::terminate()并不会保证所有类的析构函数都会被调用
//
// 标准库提供了智能指针和一系列容器来保证RAII，下方只是简单的示例
// 并且因为删除了拷贝构造函数，该类的实例不能直接返回，需要使用move
//
// 能用RAII实例的时候尽可能选择其，尽量不要使用new, new[], delete,
// delete[]等不安全的老方法
class DoubleArrayRAII final {
private:
  double *m_resourse;

public:
  DoubleArrayRAII(size_t size) : m_resourse{new double[size]} {}

  // 在析构函数中释放资源，保证资源的原子性，能够在任何情况下释放
  // 编译器会保证资源的释放，即使再有异常的情况下
  // 即使没有调用release，析构函数的调用也会释放分配的数组
  ~DoubleArrayRAII() {
    std::cout << "Freeing memory..." << std::endl;
    delete[] m_resourse;
  }

  // 删除拷贝构造函数，保证资源只会被分配和释放一次
  // 否则可能会有多个实例指向同一个数组，这样会导致分配和释放时的混乱
  DoubleArrayRAII(const DoubleArrayRAII &) = delete;

  DoubleArrayRAII &operator=(const DoubleArrayRAII &) = delete;

  // 加上一些方法能够访问和获取资源
  double &operator[](size_t index) noexcept { return m_resourse[index]; }

  const double &operator[](size_t index) const noexcept {
    return m_resourse[index];
  }

  double *get() const noexcept { return m_resourse; }

  // 这里并没有真正释放资源，而是清空该对象指向的资源并返回资源的指针
  double *release() noexcept {
    double *result = m_resourse;
    m_resourse = nullptr;
    return result;
  }
};

int main() { return 0; }
