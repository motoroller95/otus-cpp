#pragma once

#include <unordered_map>
#include <algorithm>

template<typename T, T default_value>
class Matrix
{
  class MatrixRow
  {
    friend class Matrix<T, default_value>;

    std::unordered_map<int, T> values;

    MatrixRow() {};
    MatrixRow(const MatrixRow&) = delete;
    MatrixRow(const MatrixRow&&) = delete;
    MatrixRow& operator=(const MatrixRow&) = delete;

    ~MatrixRow() {};

  public:
    T operator[](size_t idx) {
      auto it = values.find(idx);
      if (it != values)
        return it->second;
      else
        return default_value;
    }

    size_t count() {
      return values.size();
    }
  };

public:
  Matrix() {};

  MatrixRow operator[](size_t idx )
};
