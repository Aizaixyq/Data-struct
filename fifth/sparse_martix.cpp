#include "sparse_martix.hpp"

int main() {
    sm a(3, 4);
    a.push(1, 3, 1);
    a.push(2, 2, 6);
    a.print();
    a.T();
    a.print();
}