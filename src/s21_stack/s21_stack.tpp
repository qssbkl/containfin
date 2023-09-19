template <typename T>
stack<T>::stack() {
  alloc_space();

  elem_amount_ = START_AMOUNT;
}

template <typename T>
stack<T>::stack(std::initializer_list<T> const &items) {
  size_t j = START_AMOUNT;
  this->elem_amount_ = 0;
  alloc_space();

  for (auto i : items) {
    push(i);
    ++j;
  }

  this->elem_amount_ = j;
}

template <typename T>
stack<T>::stack(const stack &s) {  // to do
  if (s.empty()) {
    throw std::invalid_argument("Stack is empty");
  }
  this->top_ = s.top_;
  this->elem_amount_ = s.elem_amount_;
}

template <typename T>
stack<T>::stack(stack &&s) {
  this->top_ = s.top_;
  this->elem_amount_ = s.elem_amount_;

  s.top_ = nullptr;
  s.elem_amount_ = START_AMOUNT;
}

template <typename T>
stack<T>::~stack() {
  while (top_ != nullptr) {
    last_t<T> *iter = top_->next;

    delete top_;
    top_ = iter;
  }
}

template <typename T>
void stack<T>::push(const_reference value) {
  if (this->elem_amount_ == this->max_size()) {
    throw std::invalid_argument("Stack is full");
  }

  this->top_ = new last_t<T>{value, top_};
  this->elem_amount_ += 1;
  // ++elem_amount_;
}

template <typename T>
void stack<T>::pop() {
  if (empty()) {
    throw std::invalid_argument("Stack is empty");
  }

  last_t<T> *buff_top = top_->next;

  delete top_;

  top_ = buff_top;
  --elem_amount_;
}

template <typename T>
void stack<T>::swap(stack &other) {
  std::swap(elem_amount_, other.elem_amount_);
  std::swap(top_, other.top_);
}
template <typename T>
template <typename... Args>
void s21::stack<T>::emplace_front(
    Args &&...args) {  //  appends new elements to the top of the container
  for (const auto temp : {args...}) push(temp);
}

// template <typename T>
// stack& stack<T>::operator=(stack&& s) {
//   top_ = s.top_;
//   elem_amount_ = s.elem_amount_;

//   // to do top_
// }

template <typename T>
void stack<T>::alloc_space() {
  top_ = new last_t<T>();
}
