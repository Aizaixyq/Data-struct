#include "allocator.hpp"
#include <algorithm>
#include <iostream>

#ifndef MARTIX_H
#define MARTIX_H 1

struct triple {
    int _x, _y, _val;
    triple() : _x(0), _y(0), _val(0) {}
    triple(int x, int y, int val) : _x(x), _y(y), _val(val) {}
    void exchange() {
        int t = _x;
        _x = _y;
        _y = t;
    }
};

class sm {
private:
    triple *elem = nullptr;
    size_t _n = 0, _m = 0;
    size_t _CAP = 10;
    size_t _LEN = 0;
    Allocator<triple> alloc;

public:
    sm() { this->elem = alloc.allocator(_CAP); }
    sm(int n, int m) {
        this->_n = n;
        this->_m = m;
        this->_CAP = 10;
        this->_LEN = 0;
        this->elem = alloc.allocator(_CAP);
    }
    /**
     * @brief add new triple
     * @param x
     * @param y
     * @param val
     */
    void push(int x, int y, int val) {
        triple a(x, y, val);
        elem[this->_LEN] = a;
        ++this->_LEN;
        if (this->_LEN >= this->_CAP) {
            this->elem = alloc.expend(elem, 10);
        }
    }

    // Transposed martix
    void T() {
        std::sort(elem, elem + _LEN, [](auto &a, auto &b) {
            a.exchange();
            b.exchange();
            if (a._x == b._x) {
                return a._y < b._y;
            }
            return a._x < b._x;
        });
    }

    // displays information about this martix
    void print() {
        std::cout << "This is a(an) " << this->_n << " x " << this->_m
                  << " martix\n";
        for (int i = 0; i < _LEN; ++i) {
            std::cout << "x: " << this->elem[i]._x << " y: " << this->elem[i]._y
                      << " val: " << this->elem[i]._val << std::endl;
        }
    }
};

#endif