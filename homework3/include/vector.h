#pragma once
#include <memory>

template <typename T, typename alloc = std::allocator<T>>
struct Vector
{
  vector() {}
  void push_back(const T& item)
  {
    if (isFull())
      allocateSpace();

    array[size++] = item;
  }



private:
  bool isFull() { return capacity == size; }
  void allocateSpace()
  {
    
  }

  size_t capacity = 0;
  size_t size = 0;
  T *array = nullptr;
};
