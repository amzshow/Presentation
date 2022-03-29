#include <iostream>
#include <memory>

void func(int *p)
{
    std::unique_ptr<int> u(p);
}

int main () {
    
    int *p = new int;
    *p = 10;
//    func(p);
    std::cout << *p;
}
