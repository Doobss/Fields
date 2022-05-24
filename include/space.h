#pragma once
#include "cell.h"
#include "thread_admin.h"
#include "vector.h"

namespace Space_class {

using Cell_class::Cell;
using Thread_Admin_class::Thread_Admin;
using Vector_class::Vector;

template <typename T>
class Space {
  typedef Cell<T> *Cell_type;
  typedef Thread_Admin *thread_type;

  int *dimensions;
  int max_index;
  int max_threads;
  thread_type threads;

  Cell_type cells;

  std::thread *request_thread();
  bool handle_thread(std::thread *new_thread);
  int vector_to_index(int x, int y, int z);

 public:
  Space();
  ~Space();
  Cell_type index(int x, int y, int z);
  void thread_test();
};

}  // namespace Space_class
