#ifndef SRC_S21_ARRAY_H_
#define SRC_S21_ARRAY_H_

// #include <string>

#include <stddef.h>
#include <stdlib.h>

#include <initializer_list>
#include <utility>

namespace s21 {
template <typename T, size_t MSize>
class array {
  using value_type =
      T;  // T defines the type of an element (T is template parameter)
  using reference = T &;  // T & defines the type of the reference to an element
  using const_reference =
      const T &;  // const T & defines the type of the constant reference
  using iterator =
      T *;  // T * defines the type for iterating through the container
  using const_iterator = const T *;  // const T * defines the constant type for
                                     // iterating through the container
  using size_type =
      long unsigned int;  // size_t defines the type of the container size
                          // (standard type is size_t)

 public:
  array();  // default constructor, creates empty array
  /* initializer list constructor, creates array initizialized using
   * std::initializer_list */
  array(std::initializer_list<value_type> const &items);
  array(const array &a);  // copy constructor
  array(array &&a);       // move constructor
  ~array();               // destructor
  array &operator=(
      array &&a);  // assignment operator overload for moving object
  array &operator=(const array &a);
  reference at(size_type pos);  // access specified element with bounds checking
  reference operator[](size_type pos);  // access specified element
  const_reference front();              // access the first element
  const_reference back();               // access the last element
  iterator data();                      // direct access to the underlying array
  iterator begin();                     // returns an iterator to the beginning
  iterator end();                       // returns an iterator to the end
  bool empty();                         // checks whether the container is empty
  size_type size();                     // returns the number of elements
  size_type max_size();     // returns the maximum possible number of elements
  void swap(array &other);  // swaps the contents
  void fill(const_reference value);  // assigns the given value value to all
                                     // elements in the container.
  void print_array();

 private:
  iterator array_;
  size_type size_;
  size_type max_size_;

  void mem_alloc();
  void mem_free();
  size_type size_const() const;
  iterator begin_const() const;
};
#include "s21_array.tpp"
}  // namespace s21

#endif  // SRC_S21_ARRAY_H_
