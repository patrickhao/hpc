#include <iostream>
#include <stdexcept>

template <typename T> class Array {
private:
  T *m_elements;
  size_t m_size;

public:
  explicit Array<T>(size_t size);

  // ~Array<T>();
  // 可以省略<T>
  ~Array();

  Array<T>(const Array<T> &array);

  Array<T> &operator=(const Array<T> &rhs);

  T &operator[](size_t index);

  const T &operator[](size_t index) const;

  size_t getSize() const;
};

// 其并不是函数定义，只是函数的模版
// 无需重复加上<T>，通过::的Array都会自动加上<T>
// 实现的时候要加上模版标识，不论有没有用到T
template <typename T>
Array<T>::Array(size_t size) : m_elements{new T[size]{}}, m_size{size} {}

template <typename T> Array<T>::~Array() { delete[] m_elements; }

// 深拷贝
template <typename T>
Array<T>::Array(const Array &array) : Array{array.m_size} {
  for (size_t i{}; i < m_size; ++i) {
    m_elements[i] = array.m_elements[i];
  }
}

// size_t保证了索引的非负
template <typename T> T &Array<T>::operator[](size_t index) {
  if (index >= m_size) {
    throw std::out_of_range{"Index too large: " + std::to_string(index)};
  }
  return m_elements[index];
}

template <typename T> const T &Array<T>::operator[](size_t index) const {
  if (index >= m_size) {
    throw std::out_of_range{"Index too large: " + std::to_string(index)};
  }
  return m_elements[index];
}

// 显示实例化可以快速测试一个类模版中的成员函数是不是有问题，而不用再隐式初始化知道使用时才发现问题
template class Array<int>;

int main() {
  // 隐式实例化，在类的实例创建时才实例化类的模版，这与显示实例化是不同的
  // 实例化就是用类模版生成类的过程
  // 这种懒实例化，可能会导致直到使用前才会发现问题，类似于复制和拷贝构造函数
  // 在使用template时，编译器只会编译用到的成员函数，也就是说不是所有成员函数都会被编译，可能实际上只有模版中成员函数的一部分
  // 在使用模版与继承时，可能会出现链接无法找到函数的问题，可能就是因为这个原因
  Array<double> a{10};

  return 0;
}
