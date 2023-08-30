template <typename T> class Outer {
public:
  class Nested {};
};

// 这里最后不加typename会报错
// 编译器有时会拒绝可能正确的模版，也就导致模版有时肉眼看没问题，但是实际编译时会报错
// 编译器将其视为了确定类型，在类内部找但是没有找到
// 使用typename修饰，使编译器知道从哪里找
// 有些无法推断类型的，即使加了typename编译器也无法知道是什么类型，只知道是type
template <typename T> void someFunction() { typename Outer<T>::Nested a; }

// 有时在参数列表中也需要加typename，让编译器知道这是模版类中的嵌套类
template <typename T>
typename Outer<T>::Nested
someFunction2(const typename Outer<T>::Nested &nested) {
  return nested;
}

int main() {
  someFunction<int>();

  return 0;
}
