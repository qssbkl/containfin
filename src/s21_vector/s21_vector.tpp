template <typename T>
vector<T>::vector() : size_(0U), capacity_(0U) {
  alloc_space(0);
}

template <typename T>
vector<T>::vector(size_type n) {
  if (n == 0) {
    throw std::invalid_argument("The size is equal 0");
  }

  alloc_space(n);

  size_ = 0U;
  capacity_ = n;
}

template <typename T>
vector<T>::vector(std::initializer_list<T> const &items)
    : size_(items.size()), capacity_(items.size()) {
  alloc_space(items.size());
  size_t j = -1;

  for (auto i : items) {
    arr_[++j] = i;
  }
}

template <typename T>
vector<T>::vector(const vector &v) {
  alloc_space(v.size_);

  for (size_t i = 0; i < v.size(); i++) {
    arr_[i] = v[i];
  }

  size_ = v.size_;
  capacity_ = v.capacity_;
}

template <typename T>
vector<T>::vector(vector &&v) {
  arr_ = v.arr_;
  size_ = v.size_;
  capacity_ = v.capacity_;

  v.arr_ = nullptr;
  v.size_ = v.capacity_ = 0U;
}

template <typename T>
vector<T>::~vector() {
  delete[] arr_;
}

template <typename T>
typename vector<T>::reference vector<T>::at(size_type i) {
  if (i >= size_) {
    throw std::invalid_argument("Index out of range");
  }

  return arr_[i];
}

template <typename T>
void vector<T>::push_back(const_reference v) {
  if (full()) {
    reserve_more_capacity(capacity_ + 1);
  }

  arr_[size_] = v;
  ++size_;
}

template <typename T>
void vector<T>::pop_back() {
  if (empty()) {
    throw std::invalid_argument("The vector is empty");
  }

  --size_;
}

template <typename T>
void vector<T>::reserve(size_type size) {
  if (size == 0) {
    throw std::invalid_argument("The size is equal 0");
  } else if (size > max_size()) {
    throw std::invalid_argument("The size is larger than the max size");
  }
  T *arr = new T[size];
  size_t i = 0;
  size_t new_size = (size <= size_) ? size : size_;

  for (; i < new_size; ++i) {
    arr[i] = arr_[i];
  }
  delete[] arr_;
  capacity_ = size;
  size_ = size;
  arr_ = arr;
}

template <typename T>
void vector<T>::clear() {
  for (size_t i = 0; i < size_; ++i) {
    arr_[i] = T{};
  }

  size_ = 0U;
  capacity_ = 0U;
}

template <typename T>
void vector<T>::erase(iterator pos) {
  size_t index = pos - arr_;

  if (index > size_) {
    throw std::invalid_argument("Index out of range");
  }

  for (size_t i = index + 1; i < size_; ++i) {
    arr_[i - 1] = arr_[i];
  }

  --size_;
}

template <typename T>
void vector<T>::swap(vector &other) {
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
  std::swap(arr_, other.arr_);
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](size_t pos) {
  if (pos >= size_) {
    throw std::invalid_argument("Index out of range");
  }

  return arr_[pos];
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return arr_;
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
  return &arr_[size_];
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  size_t counter = 0, new_size = 1 + this->capacity_, index = 0;
  T *buf_arr = new T[new_size];

  for (size_t i = 0; i < this->capacity_; i++) {
    if (&this->arr_[i] == pos) {
      buf_arr[counter] = value;
      index = counter;
      counter++;
      buf_arr[counter] = this->arr_[i];
    } else {
      buf_arr[counter] = this->arr_[i];
    }
    counter++;
  }

  this->capacity_ = this->capacity_ + 1;
  this->size_ = this->size_ + 1;
  delete[] this->arr_;
  this->arr_ = buf_arr;
  return &this->arr_[index];
}

template <typename T>
void vector<T>::alloc_space(size_type n) {
  arr_ = new T[n];
}

template <typename T>
void vector<T>::reserve_more_capacity(size_type n) {
  if (n <= capacity_) {
    throw std::invalid_argument("The argument is less the capacity");
  } else if (n > max_size()) {
    throw std::invalid_argument("The size is larger than the max size");
  }

  T *buf_arr = new T[n];

  for (size_t i = 0; i < size_; i++) {
    buf_arr[i] = std::move(arr_[i]);
  }
  delete[] arr_;

  arr_ = buf_arr;
  capacity_ = n;
}

template <typename T>
template <typename... Args>
typename s21::vector<T>::iterator s21::vector<T>::emplace(const_iterator pos,
                                                          Args &&...args) {
  iterator adress = (iterator)pos;
  for (const auto temp : {args...}) {
    adress = insert(adress, temp);
  }
  return adress;
};

template <typename T>
template <typename... Args>
void s21::vector<T>::emplace_back(Args &&...args) {
  for (const auto temp : {args...}) push_back(temp);
};