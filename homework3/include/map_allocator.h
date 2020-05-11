#pragma once
#include <limits>
#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T, int chunksCount = 10>
struct MapAllocator
{
  using value_type = T;
  using pointer = T *;
  using const_pointer = const T *;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;

  template <typename Other>
  struct rebind
  {
    using other = MapAllocator<Other, chunksCount>;
  };

  MapAllocator() { getNewChunks(); }
  ~MapAllocator()
  {
    for (auto ptr : bases)
      std::free(ptr);
  }

  template <typename Other>
  MapAllocator(const MapAllocator<Other> &other) { }

  size_type max_size() const { return std::numeric_limits<size_type>::max(); }

  T *allocate(std::size_t n)
  {
    if (n != 1)
      throw std::invalid_argument("Can't allocate more than 1 element");

    if (pool.empty())
      getNewChunks();

    auto pointer = pool.back();
    pool.pop_back();

    return pointer;
  }

  void deallocate(T *p, std::size_t n) { pool.push_back(p); }

  template <typename U, typename... Args>
  void construct(U *p, Args &&... args) { new (p) U(std::forward<Args>(args)...); }

  template <typename U>
  void destroy(U *p) { p->~U(); }

private:
  void getNewChunks()
  {
    std::cout << "Allocating new " << chunksCount << " chunks" << std::endl;
    auto ptr = reinterpret_cast<T *>(std::malloc(chunksCount * sizeof(T)));
    if (ptr == nullptr)
      throw std::bad_alloc();
    bases.push_back(ptr);

    for (int i = 0; i < chunksCount; i++, ptr += sizeof(T))
      pool.push_back(ptr);
  }

  std::vector<T *> pool;
  std::vector<void *> bases;
};
