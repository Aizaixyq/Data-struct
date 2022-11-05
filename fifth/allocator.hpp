#include <cstring>
#ifndef ALLOCATOR_H_O
#define ALLOCATOR_H_O

template <typename T>
class Allocator {
    typedef unsigned long long size_t;

public:
    T *allocator() {
        T *a = new T[20];
        return a;
    }
    T *allocator(size_t n) {
        T *a = new T[n];
        return a;
    }
    T *allocator(size_t n, T x) {
        T *a = new T[n];
        for (int i = 0; i < n; ++i)
            a[i] = x;
        return a;
    }
    T *expend(T *x, size_t cap) {
        T *a = new T[cap * 2]; // not safety
        memcpy(a, x, cap * sizeof(T));
        delete[] x;
        return a;
    }
    T *expend(T *x, size_t cap, size_t n) {
        T *a = new T[cap + n]; // not safety
        memcpy(a, x, cap * sizeof(T));
        delete[] x;
        return a;
    }
};

#endif