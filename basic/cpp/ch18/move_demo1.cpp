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

  Array &operator=(const Array &rhs);

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
}
