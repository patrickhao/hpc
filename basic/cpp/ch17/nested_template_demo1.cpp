#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T> class Stack {
public:
  Stack() = default;

  ~Stack();

  Stack(const Stack &stack);

  Stack &operator=(const Stack &rhs);

  void swap(Stack &other) noexcept;

  void push(const T &item);

  T pop();

  bool isEmpty() const;

private:
  class Node {
  public:
    Node(const T &item) : m_item{item} {}

    // 因为Node类是私有的，只有该模版类可以访问其中的内容，所有其内部成员可以是public的
    T m_item;

    Node *m_next{};
  };

  Node *m_head{};
};

// 只是复制构造函数，不会影响被复制的Stack的内容
template <typename T> Stack<T>::Stack(const Stack &stack) {
  if (stack.m_head) {
    m_head = new Node{*stack.m_head};
    Node *oldNode{stack.m_head};
    Node *newNode{m_head};

    oldNode = oldNode->m_next;

    while (oldNode != nullptr) {
      newNode->m_next = new Node{*oldNode};
      newNode = newNode->m_next;

      oldNode = oldNode->m_next;
    }
  }
}

template <typename T> bool Stack<T>::isEmpty() const {
  return m_head == nullptr;
}

// 是引用，将other和当前类的实例交换
template <typename T> void Stack<T>::swap(Stack &other) noexcept {
  std::swap(m_head, other.m_head);
}

template <typename T> Stack<T> &Stack<T>::operator=(const Stack<T> &rhs) {
  auto copy{rhs};
  swap(copy);
  return *this;
}

//  传进来的是引用
template <typename T> void Stack<T>::push(const T &item) {
  // 这里的new Node是调用函数，用圆括号而不是花括号
  Node *node{new Node(item)};
  node->m_next = m_head;
  m_head = node;
}

template <typename T> T Stack<T>::pop() {
  if (isEmpty()) {
    throw std::logic_error{"Stack empty"};
  }

  auto *next{m_head->m_next};

  // 复制一个节点出来，原来的要释放
  // 这里为什么选择复制一个节点出来而不是将原有节点指针处理后返回
  T item{m_head->m_item};

  // 释放当前要出栈元素的内存空间，因为Node存的是引用，不会释放引用位置的内存
  delete m_head;

  m_head = next;

  return item;
}

// 析构函数要释放所有内存空间
// 删除完后头指针为空
/* template <typename T> Stack<T>::~Stack() { */
/*   while (m_head) { */
/*     auto *next = m_head->m_next; */
/*     delete m_head; */
/*     m_head = next; */
/*   } */
/* } */

// 这种方案可读性更强
// 现代编译器可以为两种实现生成几乎相同性能的代码
// 因此这两种实现性能差异不大，且后面这种可读性更强
template <typename T> Stack<T>::~Stack() {
  while (!isEmpty()) {
    pop();
  }
}

int main() { return 0; }
