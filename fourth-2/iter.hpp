#ifndef ITER_H
#define ITER_H 1

template <typename T>
class iter {
private:
    T *_vals;

public:
    iter(T *vals) : _vals(vals) {}

    const bool operator!=(const iter &x) { return this->_vals != x._vals; }
    const iter &operator++() {
        ++_vals;
        return *this;
    }
    T &operator*() { return *_vals; }
};
#endif