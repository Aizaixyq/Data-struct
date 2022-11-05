#include "string.hpp"
#include <iostream>
using std::cout;
using std::endl;

void test1(string &x, char c1, char c2) {
    for (auto &i : x) {
        if (i == c1)
            i = c2;
    }
}

void test2(string &x) {
    int l = 0, r = x.size() - 1;
    while (l < r) {
        swap(x[l], x[r]);
        ++l;
        --r;
    }
}

void test3(string &x, char c) {
    string res;
    for (const auto &i : x) {
        if (i != c)
            res += i;
    }
    x = res;
}

int main() {
    string S = "12345abcdef";
    cout << S << endl;
    test1(S, '1', '0');
    cout << "T1:" << S << endl;
    test2(S);
    cout << "T2:" << S << endl;
    test3(S, '0');
    cout << "T3:" << S << endl;
}