#include <iostream>
#include <vector>

template <typename T>
const T *findOptimum(const std::vector<T> &values,
                     bool (*compare)(const T &, const T &)) {
  if (values.empty()) {
    // 这里指针可以直接返回nullptr，但是如果返回值是引用，那么可以通过定义一个特殊的变量作为空引用，此处返回该变量即可
    return nullptr;
  }

  const T *optimum = &values[0];

  for (size_t i{1}; i < values.size(); ++i) {
    if (compare(values[i], *optimum)) {
      optimum = &values[i];
    }
  }
  return optimum;
}

// Comparison function prototypes:
bool less(const int &, const int &);

template <typename T> bool greater(const T &, const T &);

bool longer(const std::string &, const std::string &);

int main() {
  std::vector<int> numbers{91, 18, 92, 22, 13, 43};
  std::cout << "Minimum element: " << *findOptimum(numbers, less) << std::endl;
  std::cout << "Maximum element: " << *findOptimum(numbers, greater<int>)
            << std::endl;

  std::vector<std::string> names{"Moe",   "Larry", "Shemp",
                                 "Curly", "Joe",   "Curly Joe"};
  std::cout << "Alphabetically last name: "
            << *findOptimum(names, greater<std::string>) << std::endl;
  std::cout << "Longest name: " << *findOptimum(names, longer) << std::endl;
}

bool less(const int &one, const int &other) { return one < other; }

template <typename T> bool greater(const T &one, const T &other) {
  return one > other;
}

bool longer(const std::string &one, const std::string &other) {
  return one.length() > other.length();
}
