#include "../include/space.h"

namespace Space_class {

template <typename T>
Space<T>::Space() {  // Create new Space object

  std::cout << '\n'
            << "Creating Space: "
            << "\n";
  int x, y, z;
  std::cout << "Please enter int for x dimension " << '\n';
  std::cin >> x;
  std::cout << "Please enter int for y dimension " << '\n';
  std::cin >> y;
  std::cout << "Please enter int for z dimension " << '\n';
  std::cin >> z;

  Space<T>::max_threads = std::thread::hardware_concurrency() - 2;
  std::cout << "THREADS available = " << Space<T>::max_threads << "\n";
  Space<T>::threads = new Thread_Admin[max_threads];
  Space<T>::dimensions = new int[3]{x, y, z};
  std::cout << "Dimensions = [ x = " << x << ", y = " << y << ", z = " << z << " ]"
            << "\n";
  Space<T>::max_index = (x * y * z);
  Space<T>::cells = new Cell<T>[Space<T>::max_index];
  int i, j, k = 0;
  int initiated = 0;

  while (x > k) {
    j = 0;
    while (y > j) {
      i = 0;
      while (z > i) {
        int cell_id = Space<T>::vector_to_index(i, j, k);
        Cell<T> space_cell = Space<T>::cells[cell_id];
        // Vector<T> *cell_vector = new Vector<T>;
        space_cell.init(i, j, k, cell_id);
        Space<T>::cells[cell_id] = space_cell;
        initiated++;
        i++;
      }
      j++;
    }
    k++;
  }
  std::cout << "number of cells = " << initiated << '\n';
  std::cout << "Finished Space: "
            << "\n\n";
};

template <typename T>
Space<T>::~Space() {  // Clean up memory
  delete[] Space<T>::cells;
  delete[] Space<T>::dimensions;
  delete[] Space<T>::threads;
  std::cout << "Cleaned space" << '\n';
}

template <typename T>
int Space<T>::vector_to_index(int x, int y, int z) {  // convert 3d vector to 1d index
  int y_dim = Space<T>::dimensions[1];
  int z_dim = Space<T>::dimensions[2];
  return x + (y * z_dim) + (z * z_dim * y_dim);
};

template <typename T>
Cell<T> *Space<T>::index(int x, int y, int z) {  // grab a cell given a vector
  int index = Space<T>::vector_to_index(x, y, z);
  std::cout << "calc index = " << index << '\n';
  if (Space<T>::max_index > index && index > 0) {
    return &Space<T>::cells[index];
  }
  return nullptr;
};

template <typename T>
std::thread *Space<T>::request_thread() {
  std::thread *new_thread = nullptr;
  int number_of_threads = Space<T>::max_threads;
  int i = number_of_threads;
  while (new_thread == nullptr) {
    i = number_of_threads;
    while (i-- && new_thread == nullptr) {
      new_thread = Space<T>::threads[i].request();
    }
  }
  std::cout << "Got thread from index: " << i << "\n";
  return new_thread;
};

template <typename T>
bool Space<T>::handle_thread(std::thread *new_thread) {
  bool thread_handled = false;
  int number_of_threads = Space<T>::max_threads;
  int i = number_of_threads;
  while (!thread_handled) {
    i = number_of_threads;
    while (i-- && !thread_handled) {
      thread_handled = Space<T>::threads[i].handle(new_thread);
    }
  }
  std::cout << "Thread handled by index: " << i << "\n";
  return thread_handled;
};

};  // namespace Space_class
