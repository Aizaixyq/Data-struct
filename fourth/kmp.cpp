#include <iostream>
#include <string>
#include <vector>

/**
 * @brief
 *
 * @param str
 * @return std::vector<int>
 */
std::vector<int> prefix_function(const std::string &str) {
    auto n = str.size();
    std::vector<int> ans(n);
    for (size_t i = 1; i < n; ++i) {
        size_t j = ans[i - 1];
        while (j > 0 && str[i] != str[j])
            j = ans[j - 1];
        if (str[i] == str[j])
            j++;
        ans[i] = j;
    }
    return ans;
}

/**
 * @brief
 * find b in a, return idx \
 * if not, return -1
 * @param a
 * @param b
 * @return size_t
 */
size_t kmp(const std::string &a, const std::string &b) {
    auto n = a.size(), m = b.size();
    const std::vector<int> &next = prefix_function(b);
    size_t k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (k == m - 1) {
            return i - m + 1;
        }
        while (k > 0 && a[i] != b[k])
            next[k] == 0 ? k = 0 : k = next[k] - 1;
        if (a[i] == b[k])
            k++;
    }
    return -1;
}

int main() {
    std::string p = "abcabcd", str = "aaaaaaabcabcd";
    std::cout << kmp(str, p); //返回下标
}