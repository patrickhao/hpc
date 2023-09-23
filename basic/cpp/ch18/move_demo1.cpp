#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

template <typename T> class Array {
public:
  explicit Array(size_t size);

  ~Array();

  Array(const Array &array);

  Array(Array &&moved);

  Array &operator=(const Array &rhs);

  Array &operator=(Array &&rhs);

  void swap(Array &other) noexcept;

  T &operator[](size_t index);

  const T &operator[](size_t index) const;

  size_t getSize() const { return m_size; }

private:
  T *m_elements;

  size_t m_size;
};

template <typename T>
Array<T>::Array(size_t size) : m_elements{new T[size]{}}, m_size{size} {}

template <typename T> Array<T>::~Array() { delete[] m_elements; }

template <typename T>
Array<T>::Array(const Array &array) : Array{array.m_size} {
  std::cout << "Array of " << m_size << " elements copied" << std::endl;
  for (size_t i{}; i < m_size; ++i) {
    m_elements[i] = array.m_elements[i];
  }
}

// 加入下方构造函数后，会调用下方move构造函数
// 特定条件下编译器会自动调用move构造函数，例如通过右值进行初始化且只有一个元素是
// 实际上还是根据参数的类型调用构造函数，只是这个参数的类型是右值引用
template <typename T>
Array<T>::Array(Array &&moved)
    : m_size{moved.m_size}, m_elements{moved.m_elements} {
  std::cout << "Array of " << m_size << " elements moved" << std::endl;
  moved.m_elements = nullptr;
}

// 用户自定义的赋值构造函数通常和用户自定义的赋值构造函数相对应
template <typename T> Array<T> &Array<T>::operator=(Array &&rhs) {
  std::cout << "Array of " << rhs.m_size << " elements moved (assignment)"
            << std::endl;

  if (&rhs != this) { // 预防自我赋值
    delete[] m_elements;

    m_elements = rhs.m_elements;
    m_size = rhs.m_size;

    rhs.m_elements = nullptr;
  }

  return *this;
}

template <typename T> const T &Array<T>::operator[](size_t index) const {
  if (index >= m_size) {
    throw std::out_of_range{"Index too large: " + std::to_string(index)};
  }

  return m_elements[index];
}

// 非const运算符，使用const and back again原则
template <typename T> T &Array<T>::operator[](size_t index) {
  // 调用的是上面的const实现版本
  return const_cast<T &>(std::as_const(*this)[index]);
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &rhs) {
  Array<T> copy{rhs};
  swap(copy);
  return *this;
}

template <typename T> void Array<T>::swap(Array &other) noexcept {
  std::swap(m_elements, other.m_elements);
  std::swap(m_size, other.m_size);
}

template <typename T> void swap(Array<T> &one, Array<T> &other) noexcept {
  one.swap(other);
}

// Construct an Array<> of a given size, filled with some arbitrary string data
Array<std::string> buildStringArray(const size_t size) {
  Array<std::string> result{size};
  for (size_t i{}; i < size; ++i)
    result[i] = "You should learn from your competitor, but never copy. Copy "
                "and you die.";
  return result;
}

int main() {
  // vector中放10个Array，每个Array中有1000个元素
  const size_t numArrays{10}; // Fill 10 Arrays with 1,000 strings each
  const size_t numStringsPerArray{1000};

  std::vector<Array<std::string>> vectorOfArrays;
  // 分配足够的动态内存，这样可以将所有元素使用push_back加入vector中
  // Inform the vector<> how many Arrays we'll be adding
  vectorOfArrays.reserve(numArrays);

  for (size_t i{}; i < numArrays; ++i) {
    // 这里发生了拷贝，函数的返回值是右值
    vectorOfArrays.push_back(buildStringArray(numStringsPerArray));
  }

  // 加入move赋值函数后
  // 当赋值的变量是右值时，将调用move赋值函数
  // 因为函数返回的是一个临时变量，编译器知道这里应该使用move，因此调用了move赋值函数
  // 例如下面这种情况
  Array<std::string> strings{123};
  strings = buildStringArray(1000);

  // 但是这里调用的就是普通的赋值函数了
  // 直到more_things变量声明周期终止，其都没有被再次使用，因此这里使用复制是低效的，应当能够显示的使用move
  // 在使用move之前，保证被move的变量不会再使用，否则通常会导致程序错误
  Array<std::string> more_strings{2000};
  strings = more_strings;

  strings = std::move(more_strings);

  Array<std::string> &&rvalue_ref{std::move(more_strings)};
  // 下方的使用方法是错误的
  // 所有的变量名都是左值，即使变量表示为右值引用的形式，要想将其视为右值引用，必须加上move
  // strings = rvalue_ref;
  strings = std::move(rvalue_ref);
}
