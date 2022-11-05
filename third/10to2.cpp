#include "stack.hpp"
#include <iostream>
using std::cin;
using std::cout;

int main() {
    int a;
    cin >> a;
    stack<int> ans;

    while (a) {
        ans.push(a % 2);
        a /= 2;
    }
    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
}