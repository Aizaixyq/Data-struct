#include "complex.hpp"

int main() {
    complex a(2.4, 1), b(1.4, 1);
    complex c = a + b;
    std::cout << "Real: " << c.real << "\nImge:" << c.imge << std::endl;
    std::cout<<"hi";
}