template <typename T>
multiset<T>::BinaryTree::BinaryTree()
    : head_ptr(nullptr), all_nodes(nullptr), size(0) {}

template <typename T>
multiset<T>::BinaryTree::~BinaryTree() {
  if (this->all_nodes != nullptr) {
    delete[] this->all_nodes;
    this->all_nodes = nullptr;
  }
}

template <typename T>
void multiset<T>::BinaryTree::insert_value(const T &value) {
  if (this->head_ptr == nullptr) {
    this->head_ptr = new node;
    this->head_ptr->value = value;
    this->head_ptr->left_arm = nullptr;
    this->head_ptr->right_arm = nullptr;
  } else {
    find_place_to_add(this->head_ptr, value);
  }
}

template <typename T>
int multiset<T>::BinaryTree::find_place_to_add(iteraTor current,
                                               const T &value) {
  if (current->value >= value) {
    if (current->left_arm == nullptr) {
      current->left_arm = new node;
      current->left_arm->value = value;
      current->left_arm->left_arm = nullptr;
      current->left_arm->right_arm = nullptr;
    } else {
      find_place_to_add(current->left_arm, value);
    }
  } else {
    if (current->right_arm == nullptr) {
      current->right_arm = new node;
      current->right_arm->value = value;
      current->right_arm->left_arm = nullptr;
      current->right_arm->right_arm = nullptr;
    } else {
      find_place_to_add(current->right_arm, value);
    }
  }
  return 0;
}

template <typename T>
void multiset<T>::BinaryTree::print_all_nodes() {
  std::cout << "Hello you are in print_all_nodes() function!!!" << std::endl;
  std::cout << "\t\t                      this->size = " << this->size
            << std::endl;
  std::cout << "\t\t                Start_->head_ptr = " << this->head_ptr
            << std::endl;
  std::cout << "\t\t         Start_->head_ptr->value = "
            << this->head_ptr->value << std::endl;
  std::cout << "\t\t      Start_->head_ptr->left_arm = "
            << this->head_ptr->left_arm << std::endl;
  std::cout << "\t\t     Start_->head_ptr->right_arm = "
            << this->head_ptr->right_arm << std::endl;
  std::cout << "\t\t     Start_->head_ptr->node->pos = " << this->head_ptr->pos
            << std::endl;
  if (this->head_ptr->left_arm != nullptr &&
      this->head_ptr->right_arm != nullptr) {
    std::cout << "\tLet's print this->head_ptr->left_arm :" << std::endl;
    print_next_node(this->head_ptr->left_arm);
    std::cout << "\tLet's print this->head_ptr->right_arm :" << std::endl;
    print_next_node(this->head_ptr->right_arm);
  } else if (this->head_ptr->left_arm != nullptr) {
    std::cout << "\tLet's print this->head_ptr->left_arm :" << std::endl;
    print_next_node(this->head_ptr->left_arm);
  } else if (this->head_ptr->right_arm != nullptr) {
    std::cout << "\tLet's print this->head_ptr->right_arm :" << std::endl;
    print_next_node(this->head_ptr->right_arm);
  }
  iteraTor *temp = this->all_nodes;
  for (size_t i = 0; i < this->size; i++) {
    std::cout << "\n this->all_nodes[" << i << "] = " << this->all_nodes[i];
    std::cout << "  temp = " << temp;
    std::cout << " *temp = " << *temp;
    std::cout << " value = " << this->all_nodes[i]->value << std::endl;
    temp++;
  }
  std::cout << "By By, You are out of print_all_nodes() function!!!"
            << std::endl;
}

template <typename T>
void multiset<T>::BinaryTree::print_next_node(iteraTor node) {
  std::cout << "Hello you are in print_next_node() function!!!" << std::endl;
  std::cout << "\t\t\t\t   iteraTor node = " << node << std::endl;
  std::cout << "\t\t\t\t     node->value = " << node->value << std::endl;
  std::cout << "\t\t\t\t  node->left_arm = " << node->left_arm << std::endl;
  std::cout << "\t\t\t\t node->right_arm = " << node->right_arm << std::endl;
  std::cout << "\t\t\t\t       node->pos = " << node->pos << std::endl;
  if (node->left_arm != nullptr && node->right_arm != nullptr) {
    std::cout << "\tLet's print node->left_arm :" << std::endl;
    print_next_node(node->left_arm);
    std::cout << "\tLet's print node->right_arm :" << std::endl;
    print_next_node(node->right_arm);
  } else if (node->left_arm != nullptr) {
    std::cout << "\tLet's print node->left_arm :" << std::endl;
    print_next_node(node->left_arm);
  } else if (node->right_arm != nullptr) {
    std::cout << "\tLet's print node->right_arm :" << std::endl;
    print_next_node(node->right_arm);
  }
}

template <typename T>
void multiset<T>::BinaryTree::delete_all_nodes() {
  while (!check_for_delete(this->head_ptr)) {
    delete_next_node(this->head_ptr);
  }
  delete this->head_ptr;
}

template <typename T>
void multiset<T>::BinaryTree::delete_next_node(iteraTor node) {
  if (node != nullptr) {
    if (node->left_arm != nullptr && check_for_delete(node->left_arm)) {
      delete node->left_arm;
      node->left_arm = nullptr;
    }
    if (node->right_arm != nullptr && check_for_delete(node->right_arm)) {
      delete node->right_arm;
      node->right_arm = nullptr;
    }
    if (node->left_arm != nullptr) {
      delete_next_node(node->left_arm);
    }
    if (node->right_arm != nullptr) {
      delete_next_node(node->right_arm);
    }
  } else {
  }
}

template <typename T>
bool multiset<T>::BinaryTree::check_for_delete(iteraTor node) {
  bool answer = false;
  if (node != nullptr &&
      (node->left_arm == nullptr && node->right_arm == nullptr)) {
    answer = true;
  }
  return answer;
}

template <typename T>
void multiset<T>::BinaryTree::copy_all_nodes(const multiset &ms) {
  copy_next_node(this->head_ptr, ms.Start_.head_ptr);
}

template <typename T>
void multiset<T>::BinaryTree::copy_next_node(iteraTor dist, iteraTor source) {
  dist->value = source->value;
  dist->left_arm = nullptr;
  dist->right_arm = nullptr;
  if (source->left_arm != 0) {
    dist->left_arm = new node;
    copy_next_node(dist->left_arm, source->left_arm);
  }
  if (source->right_arm != 0) {
    dist->right_arm = new node;
    copy_next_node(dist->right_arm, source->right_arm);
  }
}

template <typename T>
typename multiset<T>::BinaryTree::iteraTor multiset<T>::BinaryTree::begin(
    iteraTor node) {
  iteraTor search = node;
  if (node->left_arm != 0) search = begin(node->left_arm);
  return search;
}

template <typename T>
typename multiset<T>::BinaryTree::iteraTor multiset<T>::BinaryTree::end(
    iteraTor node) {
  iteraTor search = node;
  if (node->right_arm != 0) search = end(node->right_arm);
  return search;
}

template <typename T>
void multiset<T>::BinaryTree::remove_node(iteraTor pos) {
  if (this->all_nodes != nullptr) {
    delete[] this->all_nodes;
    this->all_nodes = nullptr;
  }
  this->all_nodes = new node *[size];
  Key *temp = new Key[size];
  Key *temp2 = new Key[size - 1];
  size_t pos1 = 0;
  copy_tree_to_array(temp, &pos1, this->head_ptr);
  remove_node_from_array(temp, size, temp2, pos);
  delete_all_nodes();
  this->head_ptr = new node;
  fill_tree_with_array(this->head_ptr, temp2, 0, size - 2, this->all_nodes);
  delete[] temp;
  delete[] temp2;
}

template <typename T>
void multiset<T>::BinaryTree::remove_node_from_array(Key *src, size_t size,
                                                     Key *dist, iteraTor pos) {
  size_t count = 0, start = 0, stop = 0;
  for (size_t i = 0; i < size; i++) {
    if (src[i] == pos->value) start = 1;
    if (start == 0 || stop == 1) {
      dist[count] = src[i];
      count++;
    }
    if (start == 1) stop = 1;
  }
}

template <typename T>
typename multiset<T>::BinaryTree::iteraTor multiset<T>::BinaryTree::find_node(
    const Key &key) {
  iteraTor temp = nullptr;
  find_node_from_tree(this->head_ptr, key, temp);
  return temp;
}

template <typename T>
void multiset<T>::BinaryTree::find_node_from_tree(iteraTor node, const Key &key,
                                                  iteraTor &temp) {
  if (node->value == key) {
    temp = node;
  } else {
    if (node->left_arm != 0) {
      find_node_from_tree(node->left_arm, key, temp);
    }
    if (node->right_arm != 0) {
      find_node_from_tree(node->right_arm, key, temp);
    }
  }
}

template <typename T>
void multiset<T>::BinaryTree::merge_tree(const BinaryTree &src) {
  merge_nodes(src.head_ptr);
}

template <typename T>
void multiset<T>::BinaryTree::merge_nodes(iteraTor source) {
  if (source != nullptr) {
    insert_value(source->value);
    if (source->left_arm != nullptr) {
      merge_nodes(source->left_arm);
    }
    if (source->right_arm != nullptr) {
      merge_nodes(source->right_arm);
    }
  }
}

template <typename T>
void multiset<T>::BinaryTree::rebalance_tree(size_t size) {
  if (this->all_nodes != nullptr) {
    delete[] this->all_nodes;
    this->all_nodes = nullptr;
  }
  this->all_nodes = new node *[size];
  this->size = size;
  Key *temp = new Key[size];
  size_t pos = 0;
  copy_tree_to_array(temp, &pos, this->head_ptr);
  pos = 0;
  sort_array(temp, size);
  delete_all_nodes();
  this->head_ptr = new node;
  fill_tree_with_array(this->head_ptr, temp, 0, size - 1, this->all_nodes);
  delete[] temp;
}

template <typename T>
void multiset<T>::BinaryTree::fill_tree_with_array(iteraTor dest, Key *array,
                                                   size_t left, size_t right,
                                                   iteraTor *all_nodes) {
  size_t middle = left + (right - left) / 2;
  dest->value = array[middle];
  this->all_nodes[middle] = dest;
  dest->left_arm = nullptr;
  dest->right_arm = nullptr;
  dest->pos = middle;
  if (left < middle) {
    dest->left_arm = new node;
    fill_tree_with_array(dest->left_arm, array, left, middle - 1, all_nodes);
  }
  if (middle < right) {
    dest->right_arm = new node;
    fill_tree_with_array(dest->right_arm, array, middle + 1, right, all_nodes);
  }
}

template <typename T>
void multiset<T>::BinaryTree::copy_tree_to_array(Key *array, size_t *pos,
                                                 iteraTor src) {
  if (src != nullptr) {
    array[*pos] = src->value;
    *pos = *pos + 1;
    if (src->left_arm != nullptr) copy_tree_to_array(array, pos, src->left_arm);
    if (src->right_arm != nullptr)
      copy_tree_to_array(array, pos, src->right_arm);
  }
}

template <typename T>
void multiset<T>::BinaryTree::sort_array(Key *array, size_t size) {
  if (size > 1) {
    size_t middle = size / 2;
    size_t rem = size - middle;
    Key *left_array = new Key[middle];
    Key *right_array = new Key[rem];
    for (size_t i = 0; i < size; i++) {
      if (i < middle) {
        left_array[i] = array[i];
      } else {
        right_array[i - middle] = array[i];
      }
    }
    sort_array(left_array, middle);
    sort_array(right_array, rem);
    merge_array(array, left_array, middle, right_array, rem);
    delete[] left_array;
    delete[] right_array;
  }
}

template <typename T>
void multiset<T>::BinaryTree::merge_array(Key *array, Key *left_array,
                                          size_t size_left, Key *right_array,
                                          size_t size_right) {
  size_t i = 0, j = 0;
  while (i < size_left || j < size_right) {
    if (i < size_left && j < size_right) {
      if (left_array[i] <= right_array[j]) {
        array[i + j] = left_array[i];
        i++;
      } else {
        array[i + j] = right_array[j];
        j++;
      }
    } else if (i < size_left) {
      array[i + j] = left_array[i];
      i++;
    } else if (j < size_right) {
      array[i + j] = right_array[j];
      j++;
    }
  }
}

template <typename T>
size_t multiset<T>::BinaryTree::count_nodes(const Key &key) {
  size_t count = 0;
  iteraTor temp = find_node(key);
  if (temp != nullptr) {
    count++;
    size_t pos = temp->pos;
    if (pos > 0) {
      pos--;
      while (true) {
        if (this->all_nodes[pos]->value == key) {
          count++;
        } else {
          break;
        }
        if (pos == 0) break;
        pos--;
      }
    }
    pos = temp->pos;
    if (pos < this->size) {
      pos++;
      while (pos < this->size) {
        if (this->all_nodes[pos]->value == key) {
          count++;
        } else {
          break;
        }
        pos++;
      }
    }
  }
  return count;
}

template <typename T>
multiset<T>::multiset() : Start_(), size_(0U) {}

template <typename T>
multiset<T>::multiset(std::initializer_list<value_type> const &items) {
  this->size_ = 0;
  size_t size = items.size();
  auto *p = items.begin();
  this->Start_.head_ptr = nullptr;
  this->Start_.all_nodes = nullptr;
  for (size_t i = this->size_; i < size; i++) {
    this->Start_.insert_value(*p);
    p++;
    this->size_ = this->size_ + 1;
  }
  this->Start_.rebalance_tree(this->size_);
}

template <typename T>
multiset<T>::multiset(const multiset &ms) {
  this->Start_.head_ptr = new node;
  this->Start_.copy_all_nodes(ms);
  this->size_ = ms.size_;
  this->Start_.rebalance_tree(this->size_);
}

template <typename T>
multiset<T>::multiset(multiset &&ms) {
  this->size_ = 0;
  this->Start_.head_ptr = nullptr;
  this->Start_.all_nodes = nullptr;
  this->Start_.head_ptr = new node;
  this->Start_.copy_all_nodes(ms);
  this->size_ = ms.size_;
  this->Start_.rebalance_tree(this->size_);
  ms.Start_.delete_all_nodes();
  ms.size_ = 0;
}

template <typename T>
multiset<T>::~multiset() {
  if (this->size_ > 0) {
    this->Start_.delete_all_nodes();
    this->Start_.~BinaryTree();
  }
}

template <typename T>
typename multiset<T>::multiset multiset<T>::operator=(multiset &&ms) {
  if (this->size_ > 0) {
    this->Start_.delete_all_nodes();
    this->Start_.head_ptr = nullptr;
    delete[] this->Start_.all_nodes;
    this->Start_.all_nodes = nullptr;
    this->size_ = 0;
  }
  this->Start_.head_ptr = new node;
  this->Start_.copy_all_nodes(ms);
  this->size_ = ms.size_;
  this->Start_.rebalance_tree(this->size_);
  ms.Start_.delete_all_nodes();
  ms.size_ = 0;
  return *this;
}

template <typename T>
typename multiset<T>::multiset &multiset<T>::operator=(const multiset &ms) {
  if (this != &ms) {
    if (this->size_ > 0) {
      this->Start_.delete_all_nodes();
      this->size_ = 0;
    }
    this->Start_.head_ptr = new node;
    this->Start_.copy_all_nodes(ms);
    this->size_ = ms.size_;
    this->Start_.rebalance_tree(this->size_);
  }
  return *this;
}

template <typename T>
typename multiset<T>::iterator multiset<T>::begin() {
  typename BinaryTree::iteraTor temp = this->Start_.head_ptr;
  temp = this->Start_.begin(temp);
  return &this->Start_.all_nodes[temp->pos];
}

template <typename T>
typename multiset<T>::iterator multiset<T>::end() {
  typename BinaryTree::iteraTor temp = this->Start_.head_ptr;
  temp = this->Start_.end(temp);
  return &this->Start_.all_nodes[temp->pos];
}

template <typename T>
bool multiset<T>::empty() {
  return this->size_ == 0 ? false : true;
}

template <typename T>
typename multiset<T>::size_type multiset<T>::size() {
  return this->size_;
}

template <typename T>
typename multiset<T>::size_type multiset<T>::max_size() {
  return (size_t)-1;
}

template <typename T>
void multiset<T>::clear() {
  if (this->size_ > 0) {
    this->Start_.delete_all_nodes();
    delete[] this->Start_.all_nodes;
    this->Start_.all_nodes = nullptr;
    this->size_ = 0;
  }
}

template <typename T>
typename multiset<T>::iterator multiset<T>::insert(const T &value) {
  if (this->size_ == 0) {
    this->Start_.head_ptr = new node;
    this->Start_.head_ptr->value = value;
    this->Start_.head_ptr->left_arm = nullptr;
    this->Start_.head_ptr->right_arm = nullptr;
    this->size_ = 1;
  } else {
    this->Start_.insert_value(value);
    this->size_ = this->size_ + 1;
  }
  this->Start_.rebalance_tree(this->size_);
  return find(value);
}

template <typename T>
void multiset<T>::erase(iterator pos) {
  if (pos != nullptr) {
    this->Start_.remove_node(*pos);
    this->size_ = this->size_ - 1;
    this->Start_.rebalance_tree(this->size_);
  }
}

template <typename T>
void multiset<T>::swap(multiset &other) {
  multiset<T> temp(other);
  other = *this;
  *this = temp;
}

template <typename T>
void multiset<T>::merge(const multiset &other) {
  this->Start_.merge_tree(other.Start_);
  this->size_ = this->size_ + other.size_;
  this->Start_.rebalance_tree(this->size_);
}

template <typename T>
typename multiset<T>::size_type multiset<T>::count(const Key &key) {
  size_type count = this->Start_.count_nodes(key);
  return count;
}

template <typename T>
typename multiset<T>::iterator multiset<T>::find(const Key &key) {
  typename BinaryTree::iteraTor temp;
  temp = this->Start_.find_node(key);
  return (temp != nullptr ? (&this->Start_.all_nodes[temp->pos]) : nullptr);
}

template <typename T>
bool multiset<T>::contains(const Key &key) {
  bool found = false;
  typename BinaryTree::iteraTor temp;
  temp = this->Start_.find_node(key);
  if (temp != nullptr) found = true;
  return found;
}

template <typename T>
std::pair<typename multiset<T>::iterator, typename multiset<T>::iterator>
multiset<T>::equal_range(const Key &key) {
  return std::make_pair(this->lower_bound(key), this->upper_bound(key));
}

template <typename T>
typename multiset<T>::iterator multiset<T>::lower_bound(const Key &key) {
  typename BinaryTree::iteraTor temp;
  temp = this->Start_.find_node(key);
  iterator lower_bound = nullptr;
  if (temp != nullptr) {
    size_t pos = temp->pos;
    while (pos > 0 && this->Start_.all_nodes[pos]->value == key) {
      pos--;
    }
    lower_bound = &this->Start_.all_nodes[pos];
  }
  return lower_bound;
}

template <typename T>
typename multiset<T>::iterator multiset<T>::upper_bound(const Key &key) {
  typename BinaryTree::iteraTor temp;
  temp = this->Start_.find_node(key);
  iterator upper_bound = nullptr;
  if (temp != nullptr) {
    size_t pos = temp->pos;
    while (pos < this->size_ && this->Start_.all_nodes[pos]->value == key) {
      pos++;
    }
    if (pos + 1 < this->size_) pos++;
    if (pos == this->size_) pos--;
    upper_bound = &this->Start_.all_nodes[pos];
  }
  return upper_bound;
}

template <typename T>
template <typename... Args>
vector<std::pair<typename s21::multiset<T>::iterator, bool>>
s21::multiset<T>::emplace(Args &&...args) {
  iterator address = nullptr;
  for (const auto temp : {args...}) address = insert(temp);
  vector<std::pair<iterator, bool>> answer = {
      std::make_pair(address, sizeof...(Args) ? true : false)};
  return answer;
}

template <typename T>
void multiset<T>::print_multiset() {
  std::cout << "Hello you are in print_multiset() function!!!" << std::endl;
  std::cout << "We have got this->size_ = " << this->size_ << std::endl;
  if (this->size_ == 0) {
    std::cout << "Sorry, nothin to print" << std::endl;
  } else {
    this->Start_.print_all_nodes();
  }
  std::cout << "By By You are out of print_multiset() function!!!" << std::endl;
}
