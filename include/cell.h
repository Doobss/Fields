#pragma once
#include <iostream>

#include "vector.h"

namespace Cell_class {

using Vector_class::Vector;

template <typename T>
class Cell {
 public:
  int *vector;
  int index;
  Vector<T> *data;
  void init(int x, int y, int z, int index, Vector<T> *init_data = nullptr);
  ~Cell();
};

}  // namespace Cell_class
