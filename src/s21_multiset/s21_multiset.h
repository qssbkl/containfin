#ifndef SRC_S21_MULTISET_H_
#define SRC_S21_MULTISET_H_

#include <initializer_list>

#include "../s21_vector/s21_vector.h"

namespace s21 {

template <typename T>
class multiset {
 private:
  struct node {
    T value;
    node *left_arm;
    node *right_arm;
    size_t pos;
  };

  class BinaryTree {
   public:
    using Key = T;
    using const_iteraTor = const struct node *;
    using iteraTor = struct node *;
    using iterator = iteraTor *;
    using const_iterator = const_iteraTor *;
    using reference = BinaryTree &;
    iteraTor head_ptr;
    iterator all_nodes;
    size_t size;
    BinaryTree();
    ~BinaryTree();
    void insert_value(const T &value);
    int find_place_to_add(iteraTor current, const T &value);
    void print_all_nodes();
    void print_next_node(iteraTor node);
    void delete_all_nodes();
    void delete_next_node(iteraTor node);
    bool check_for_delete(iteraTor node);
    void copy_all_nodes(const multiset &ms);
    void copy_next_node(iteraTor dist, iteraTor source);
    iteraTor begin(iteraTor node);
    iteraTor end(iteraTor node);
    void remove_node(iteraTor pos);
    void remove_node_from_array(Key *src, size_t size1, Key *dist,
                                iteraTor pos);
    iteraTor find_node(const Key &key);
    void find_node_from_tree(iteraTor node, const Key &key, iteraTor &temp);
    void merge_tree(const BinaryTree &src);
    void merge_nodes(iteraTor source);
    void rebalance_tree(size_t size);
    void fill_tree_with_array(iteraTor node, Key *array, size_t left,
                              size_t right, iteraTor *all_nodes);
    void copy_tree_to_array(Key *array, size_t *pos, iteraTor src);
    void sort_array(Key *array, size_t size);
    void merge_array(Key *array, Key *left_array, size_t size_left,
                     Key *right_array, size_t size_right);
    size_t count_nodes(const Key &key);
  };

 public:
  using Key = T;
  using key_type = Key;    // the first template parameter (Key)
  using value_type = Key;  // value type (the value itself is a key)
  using reference =
      value_type &;  // defines the type of the reference to an element
  using const_reference =
      const value_type &;  // defines the type of the constant reference
  /* or BinaryTree::iterator as internal iterator of tree subclass;
   defines the type for iterating through the container */
  using iterator = typename BinaryTree::iterator;
  /* or BinaryTree::const_iterator as internal const iterator of tree subclass;
  defines the constant type for iterating through the container */
  using const_iterator = typename BinaryTree::const_iterator;
  using size_type = size_t;  // defines the type of the container size (standard
                             // type is size_t)

  multiset();  // default constructor, creates empty set
  /* initializer list constructor, creates the set initizialized using
   * std::initializer_list */
  multiset(std::initializer_list<value_type> const &items);
  multiset(const multiset &ms);  // copy constructor
  multiset(multiset &&ms);       // move constructor
  ~multiset();                   // destructor
  multiset operator=(
      multiset &&ms);  //  assignment operator overload for moving object
  multiset &operator=(const multiset &ms);
  iterator begin();  // returns an iterator to the beginning
  iterator end();    // returns an iterator to the end

  bool empty();          // checks whether the container is empty
  size_type size();      // returns the number of elements
  size_type max_size();  // returns the maximum possible number of elements

  void clear();  // clears the contents
  iterator insert(
      const value_type &value);  // inserts node and returns iterator to where
                                 // the element is in the container
  void erase(iterator pos);      // erases element at pos
  void swap(multiset &other);    // swaps the contents
  void merge(const multiset &other);  // splices nodes from another container
  size_type count(
      const Key &key);  // returns the number of elements matching specific key
  iterator find(const Key &key);  // finds element with specific key
  bool contains(const Key &key);  // checks if the container contains element
                                  // with specific key
  std::pair<iterator, iterator> equal_range(
      const Key &key);  //  returns range of elements matching a specific key
  iterator lower_bound(const Key &key);  // returns an iterator to the first
                                         // element not less than the given key
  iterator upper_bound(const Key &key);  // returns an iterator to the first
                                         // element greater than the given key
  void print_multiset();
  template <typename... Args>
  vector<std::pair<iterator, bool>> emplace(Args &&...args);

  BinaryTree Start_;
  size_type size_;
};
#include "s21_multiset.tpp"
}  // namespace s21

#endif  // SRC_S21_MULTISET_H_
