#include <iostream>
#include <boost/shared_ptr.hpp>

int main () {
  int* p = new int (10);
  boost::shared_ptr<int> a (p);

  if (a.get()==p)
    std::cout << "a and p point to the same location\n";

  // three ways of accessing the same address:
  std::cout << *a.get() << "\n";
  std::cout << *a << "\n";
  std::cout << *p << "\n";

  return 0;
}
