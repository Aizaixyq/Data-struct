#include<iostream>
#include<math.h>
#ifndef COMPLEX_HPP
#define COMPLEX_HPP 1

struct complex{
    double real, imge;
    complex():real(0), imge(0) {}
    complex(double r, double i):real(r), imge(i) {}

    complex operator + (const complex &a){
        complex c;
        c.real = this->real + a.real;
        c.imge = this->imge + a.imge;
        return c;
    }

    complex operator - (const complex &a){
        complex c;
        c.real = this->real - a.real;
        c.imge = this->imge - a.imge;
        return c;
    }
};
#endif