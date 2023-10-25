#include <cmath>   // For std::abs()
#include <cstddef> // For std::size_t	(required here by some compilers)
#include <iostream>
#include <optional>
#include <vector>

template <typename T, typename Comparison>
const T *findOptimum(const std::vector<T> &values, Comparison compare) {
  if (values.empty())
    return nullptr;

  const T *optimum{&values[0]};
  for (size_t i{1}; i < values.size(); ++i) {
    if (compare(values[i], *optimum))
      optimum = &values[i];
  }
  return optimum;
}

class Finder {
public:
  double getNumberToSearchFor() const;
  void setNumberToSearchFor(double n);

  std::optional<double> findNearest(const std::vector<double> &values) const;

private:
  double m_number_to_search_for{};
};

std::optional<double>
Finder::findNearest(const std::vector<double> &values) const {
  if (values.empty())
    return std::nullopt;
  else
    // 成员变量无法直接被捕获，只能捕获当前作用域内的局部变量
    // 通过传入this，访问变量无需加上this，直接按照常规方式访问类的成员变量即可
    // 可以访问类中的所有protected和private成员，也可以调用类的成员函数
    // 无需加上this->，编译器帮助生成了
    // this也可以和其他方法绑定，例如
    // [=, this], [this, &counter] , and [x, this, &counter]
    return *findOptimum(values, [this](double x, double y) {
      return std::abs(x - m_number_to_search_for) <
             std::abs(y - m_number_to_search_for);
    });
}

double Finder::getNumberToSearchFor() const { return m_number_to_search_for; }

void Finder::setNumberToSearchFor(double value) {
  m_number_to_search_for = value;
}

int main() {
  std::vector<double> numbers{91, 18, 92, 22, 13, 43};

  int number_to_search_for{};
  std::cout << "Please enter a number: ";
  std::cin >> number_to_search_for;

  Finder finder;
  finder.setNumberToSearchFor(number_to_search_for);
  std::cout << "The number nearest to " << finder.getNumberToSearchFor()
            << " is " << *finder.findNearest(numbers) << std::endl;
}