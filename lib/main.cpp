#include "cell.cpp"
#include "space.cpp"

int main() {
  using Cell_class::Cell;
  using Space_class::Space;
  using Vector_class::Vector;
  typedef int data_type;

  typedef Cell<data_type> *Cell_type;
  typedef Space<data_type> Space_type;
  Space_type space;

  typedef Vector<data_type> vec_type;
  vec_type a_vec = Vector<data_type>(4, 5, 6);
  vec_type b_vec = Vector<data_type>(5, 4, 3);
  a_vec.print();
  b_vec.print();
  vec_type c_vec = a_vec + b_vec;
  float mag_dif = a_vec ^ b_vec;
  std::cout << "mag_dif = " << mag_dif << '\n';

  c_vec.print();
  std::cout << a_vec.mag() << '\n';
  std::cout << b_vec.mag() << '\n';
  std::cout << c_vec.mag() << '\n';
  // Cell_type cell_at_index = space.index(1, 2, 1);
  // std::cout << "cell->index = " << cell_at_index->index << '\n';
}