#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 4);
    Point P(2, 2);
    Point P1(5, 5);
    Point P2(2, 0);


    if (bsp(a, b, c, P) == true) {
        std::cout << "Point is inside the triangle" << std::endl;
    } else {
        std::cout << "Point is outside the triangle" << std::endl;
    }
    return 0;
}