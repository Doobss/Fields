#include "../include/cell.h"

namespace Cell_class {

template <typename T>
void Cell<T>::init(int x, int y, int z, int index, Vector<T> *init_data) {
  Cell<T>::vector = new int[3]{x, y, z};
  Cell<T>::index = index;
  Cell<T>::data = init_data;
};

template <typename T>
Cell<T>::~Cell<T>() {
  delete[] Cell<T>::vector;
  delete data;
}

}  // namespace Cell_class