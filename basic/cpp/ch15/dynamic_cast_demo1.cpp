#include <iostream>

class Box {
public:
  // 必须要实现了多态，即至少有一个虚函数，只有多态中提供了必要的信息供dynamic_cast判断转换的合法性
  virtual ~Box() = default;

  void doSomething();
};

class Carton : public Box {
public:
  virtual ~Carton() = default;

  void funcCarton() { std::cout << "Carton" << std::endl; }
};

class FoodContainer {
public:
  virtual ~FoodContainer() = default;

  void funcFoodContainer() { std::cout << "FoodContainer" << std::endl; }
};

class CerealPack : public Carton, public FoodContainer {
public:
  virtual ~CerealPack() = default;

  void funcCerealPack() { std::cout << "CerealPack" << std::endl; }
};

// 这是一种比较巧的做法，这里的类型转换必须从窄到宽，因为CerealPack也包含Carton的信息
// 所以转Carton也能转，因此如果调换if的顺序这里的类型判断会出错
// 并且这里只能在类外实现函数，要等所有子类都定义完了才能实现
//
// 同时注意，这里的实现并非最优，而是展示可以对this指针做动态类型转换
// 一般如果涉及到对类型进行大量的判断，考虑使用多态实现更优雅
//
// 向下转换类型通常不是最好的解决方案，通常有多态等更好的实现方式，所以不要轻易尝试这样做
void Box::doSomething() {
  if (dynamic_cast<CerealPack *>(this)) {
    std::cout << "Carton object" << std::endl;
  } else if (dynamic_cast<Carton *>(this)) {
    std::cout << "CerealPack object" << std::endl;
  }
}

int main() {

  Box *box{new CerealPack};

  // 只能在同一继承关系中应用dynamic_cast
  // 如果转换不成功，会返回空指针
  // 动态转换一个比较好的地方，转换失败会返回空指针，而不是未定义的行为
  // 可以进行类型转换之后调用派生类中的非虚方法
  Carton *carton{dynamic_cast<Carton *>(box)};

  // 在进行动态转换的时候，如果转换失败会返回空指针，因此为了防止对空指针调用方法
  // 在使用前先判断是否转换成功，即是否为空
  //
  // 对引用的转换如果失败会抛出异常，因为没有对空指针的引用，通常使用引用是用一个特定的值表示引用值为空的情况
  if (carton) {
    carton->funcCarton();
  }

  // 将其从一个基类的指针转到另一个基类的指针，在多继承的情况下使用
  // 转换成功的前提，基类指针中所包含的派生类要有目标指针类类型中的信息
  FoodContainer *foodContainer{dynamic_cast<FoodContainer *>(box)};

  if (foodContainer) {
    foodContainer->funcFoodContainer();
  }

  box->doSomething();

  return 0;
}
