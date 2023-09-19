#ifndef S21_VECTOR_
#define S21_VECTOR_

#include <initializer_list>
#include <iostream>
#include <utility>

namespace s21 {
template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;
  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();

  reference at(size_type i);
  const_reference front() const { return arr_[0]; };
  const_reference back() const { return arr_[size_ - 1]; };
  void push_back(const_reference v);
  void pop_back();
  void reserve(size_type size);
  void shrink_to_fit();
  void clear();
  void erase(iterator pos);
  void swap(vector &other);

  reference operator[](size_t pos);
  const_reference operator[](size_t pos) const { return arr_[pos]; };

  iterator begin();
  const_iterator begin() const { return arr_; };
  iterator end();
  const_iterator end() const { return &arr_[size_]; };
  iterator data() const { return arr_; };
  iterator insert(iterator pos, const_reference value);

  size_type capacity() const { return capacity_; };
  size_type size() const { return size_; };
  size_type max_size() const { return SIZE_MAX / sizeof(value_type); };
  bool empty() const { return size() == 0U; };

  template <typename... Args>
  iterator emplace(const_iterator pos, Args &&...args);
  template <typename... Args>
  void emplace_back(Args &&...args);

 private:
  size_t size_;
  size_t capacity_;
  T *arr_;

  void alloc_space(size_type n);
  void reserve_more_capacity(size_type n);
  bool full() const { return size() >= capacity(); }
};
#include "s21_vector.tpp"
}  // namespace s21

#endif  // S21_VECTOR_
