#include <iostream>
#include <math.h>
#ifndef THREE_HPP
#define THREE_HPP 1

struct Three {
    int one, two, three;
    Three() : one(0), two(0), three(0) {}
    Three(int a, int b, int c) : one(a), two(b), three(c) {}

    void max_min() {
        std::cout << "Max: " << std::max(std::max(one, two), three)
                  << std::endl;
        std::cout << "Min: " << std::min(std::min(one, two), three);
    }
};
#endif