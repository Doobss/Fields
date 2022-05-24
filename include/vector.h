#pragma once
#include <cmath>

namespace Vector_class {

template <typename T>
struct Vector {
  int *dimensions;
  Vector(T x = 0, T y = 0, T z = 0) {
    dimensions = new int[3]{x, y, z};
  };
  Vector<T> operator+(const Vector<T> &b) {
    T *a_dims = this->dimensions;
    T *b_dims = b.dimensions;
    return Vector<T>((a_dims[0] + b_dims[0]), (a_dims[1] + b_dims[1]), (a_dims[2] + b_dims[2]));
  };
  Vector<T> operator-(const Vector<T> &b) {
    T *a_dims = this->dimensions;
    T *b_dims = b.dimensions;
    return Vector<T>((a_dims[0] - b_dims[0]), (a_dims[1] - b_dims[1]), (a_dims[2] - b_dims[2]));
  };

  float operator^(const Vector<T> &b) {
    Vector<T> dif = *this - b;
    return dif.mag();
  };

  float mag() {
    T *a_dims = this->dimensions;
    float x_pow = static_cast<float>(pow(a_dims[0], 2));
    float y_pow = static_cast<float>(pow(a_dims[1], 2));
    float z_pow = static_cast<float>(pow(a_dims[2], 2));
    return pow((x_pow + y_pow + z_pow), 0.5);
  }

  ~Vector() {
    delete[] dimensions;
  };
  void print() {
    std::cout << "Vec "
              << "[";
    int i = 0;
    while (3 > i) {
      std::cout << " " << dimensions[i];
      i++;
    }
    std::cout << " ] "
              << "\n";
  }
};
};  // namespace Vector_class