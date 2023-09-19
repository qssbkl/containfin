#ifndef S21_STACK_
#define S21_STACK_

#include <cstddef>
#include <initializer_list>
#include <iostream>

#define START_AMOUNT 0;

namespace s21 {

template <typename T>
struct last_t {
  T elem;
  struct last_t<T> *next;
};

template <typename T>
class stack {
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 public:
  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);  // to do
  stack(stack &&s);
  ~stack();

  void push(const_reference value);
  void pop();
  void swap(stack &other);
  bool empty() const { return !size(); };
  size_type size() const { return elem_amount_; };
  size_type max_size() const { return SIZE_MAX / sizeof(value_type); };
  const_reference top() const { return top_->elem; };
  stack &operator=(stack &&s);  // to do
  template <typename... Args>
  void emplace_front(
      Args &&...args);  //  appends new elements to the top of the container

 private:
  size_t elem_amount_;
  struct last_t<T> *top_;

  void alloc_space();
};
#include "s21_stack.tpp"
}  // namespace s21

#endif  // S21_STACK_
