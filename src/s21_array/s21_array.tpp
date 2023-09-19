
template <typename T, size_t MSize>
array<T, MSize>::array() : array_(nullptr), size_(0), max_size_(MSize) {}

template <typename T, size_t MSize>
array<T, MSize>::array(std::initializer_list<value_type> const &items) {
  this->size_ = items.size();
  this->max_size_ = MSize;
  mem_alloc();
  auto *p = items.begin();
  for (size_t i = 0; i < this->size_; i++) {
    this->array_[i] = *p;
    p++;
  }
  for (size_t i = this->size_; i < this->max_size_; i++) {
    if constexpr (std::is_same_v<T, std::string>) {
      this->array_[i] = "0";
    } else {
      this->array_[i] = 0;
    }
  }
}

template <typename T, size_t MSize>
array<T, MSize>::array(const array &a) {
  this->max_size_ = MSize;
  this->size_ = a.size_const();
  mem_alloc();
  auto *p = a.begin_const();
  for (size_t i = 0; i < this->size_; i++) {
    this->array_[i] = *p;
    p++;
  }
  for (size_t i = this->size_; i < this->max_size_; i++) {
    if constexpr (std::is_same_v<T, std::string>) {
      this->array_[i] = "0";
    } else {
      this->array_[i] = 0;
    }
  }
}

template <typename T, size_t MSize>
array<T, MSize>::array(array &&a) {
  if (&a != this) {
    this->size_ = 0;
    this->array_ = nullptr;
    *this = a;
    a.~array();
  }
}

template <typename T, size_t MSize>
array<T, MSize>::~array() {
  mem_free();
}

template <typename T, size_t MSize>
array<T, MSize> &array<T, MSize>::operator=(array &&a) {
  *this = a;
  a.~array();
  return *this;
}

template <typename T, size_t MSize>
array<T, MSize> &array<T, MSize>::operator=(const array &a) {
  this->max_size_ = MSize;
  auto *p = a.begin_const();
  size_t temp_size = (size_t)a.size_const();
  if (this->size_ != 0) {
    if (this->max_size_ > temp_size) {
      this->size_ = a.size_const();
      for (size_t i = 0; i < temp_size; i++) {
        this->array_[i] = *p;
        p++;
      }
      for (size_t i = temp_size; i < this->max_size_; i++) {
        if constexpr (std::is_same_v<T, std::string>) {
          this->array_[i] = "0";
        } else {
          this->array_[i] = 0;
        }
      }
    } else {
      for (size_t i = 0; i < this->size_; i++) {
        this->array_[i] = *p;
        p++;
      }
    }
  } else {
    this->size_ = a.size_const();
    mem_alloc();
    for (size_t i = 0; i < this->size_; i++) {
      this->array_[i] = *p;
      p++;
    }
    for (size_t i = temp_size; i < this->max_size_; i++) {
      if constexpr (std::is_same_v<T, std::string>) {
        this->array_[i] = "0";
      } else {
        this->array_[i] = 0;
      }
    }
  }
  return *this;
}

template <typename T, size_t MSize>
typename array<T, MSize>::reference array<T, MSize>::at(size_type pos) {
  if (empty()) {
    throw std::invalid_argument("Array is empty in at() function");
  }
  return array_[pos];
}

template <typename T, size_t MSize>
typename array<T, MSize>::reference array<T, MSize>::operator[](size_type pos) {
  if (empty()) {
    throw std::invalid_argument("Array is empty in operator[] function");
  }
  return array_[pos];
}

template <typename T, size_t MSize>
typename array<T, MSize>::const_reference array<T, MSize>::front() {
  return array_[0];
}

template <typename T, size_t MSize>
typename array<T, MSize>::const_reference array<T, MSize>::back() {
  return array_[size_ - 1];
}

template <typename T, size_t MSize>
typename array<T, MSize>::iterator array<T, MSize>::data() {
  return &array_[0];
}

template <typename T, size_t MSize>
typename array<T, MSize>::iterator array<T, MSize>::begin() {
  return &array_[0];
}

template <typename T, size_t MSize>
typename array<T, MSize>::iterator array<T, MSize>::begin_const() const {
  return &array_[0];
}

template <typename T, size_t MSize>
typename array<T, MSize>::iterator array<T, MSize>::end() {
  return &array_[size_ - 1];
}

template <typename T, size_t MSize>
bool array<T, MSize>::empty() {
  return this->size_ ? false : true;
}

template <typename T, size_t MSize>
typename array<T, MSize>::size_type array<T, MSize>::size() {
  return size_;
}

template <typename T, size_t MSize>
typename array<T, MSize>::size_type array<T, MSize>::size_const() const {
  return size_;
}

template <typename T, size_t MSize>
typename array<T, MSize>::size_type array<T, MSize>::max_size() {
  return max_size_;
}

template <typename T, size_t MSize>
void array<T, MSize>::swap(array &other) {
  array<T, MSize> temp(other);
  other = *this;
  *this = temp;
}

template <typename T, size_t MSize>
void array<T, MSize>::fill(const_reference value) {
  if (!empty()) {
    for (size_t i = 0; i < this->size_; i++) {
      this->array_[i] = (reference)value;
    }
  }
}

template <typename T, size_t MSize>
void array<T, MSize>::mem_alloc() {
  this->array_ = new T[max_size_];
}

template <typename T, size_t MSize>
void array<T, MSize>::mem_free() {
  if (!empty()) {
    delete[] this->array_;
    this->size_ = 0;
    this->max_size_ = 0;
    this->array_ = nullptr;
  }
}

template <typename T, size_t MSize>
void array<T, MSize>::print_array() {
  if (this->size_ > 0 && this->max_size_ < 20) {
    for (size_t i = 0; i < this->max_size_; i++) {
      std::cout << this->array_[i] << " ";
    }
  }
  std::cout << std::endl;
  std::cout << "      size_ = " << this->size_ << std::endl;
  std::cout << "  max_size_ = " << this->max_size_ << std::endl;
  std::cout << " value_type = " << typeid(T).name() << std::endl;
  std::cout << std::endl;
}
