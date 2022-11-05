#include "string.hpp"
#include <iostream>

using std::cin;
using std::cout;

void test() {
    string a = "abc1234567890123456";
    a[-1] = 'a';
    a += "av";
    string b;
    cin >> b;
    b += a;
    cout << b << std::endl;
    a = "acc";
    cout << a;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << a << std::endl;
    cout << b << std::endl;
    string c = a + b;
    cout << c;
}