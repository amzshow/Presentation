#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

int main () {
    using namespace boost::numeric::ublas;
    vector<double> v (3);	//{0, 0, 0}
    vector<double> x(3,1);	//{1, 1, 1}
    for (unsigned i = 0; i < v.size (); ++ i)
        v (i) = i+1;
        
    v *= 4;
    v /= 2;
    x *= 10;
    v += x;
    // Requires a another vector for addition and subtraction.
    // Does NOT require any vector, a number would work fine for multiplication and division.
    
    std::cout << v << std::endl;
}
