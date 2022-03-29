#include <iostream>
#include <memory>

struct C {int* data;};

int main () {
  std::shared_ptr<int> p1;
  std::shared_ptr<int> p2 (nullptr);
  std::shared_ptr<int> p3 (new int);
  std::shared_ptr<int> p4 (new int);
  std::shared_ptr<int> p5 (p4);


  std::cout << "use_count:\n";
  std::cout << "p1: " << p1.use_count() << '\n';
  std::cout << "p2: " << p2.use_count() << '\n';
  std::cout << "p3: " << p3.use_count() << '\n';
  std::cout << "p4: " << p4.use_count() << '\n';
  std::cout << "p5: " << p5.use_count() << '\n';

  return 0;
}
