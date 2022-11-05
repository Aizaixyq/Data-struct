#include "allocator.hpp"
#include "iter.hpp"
#include <cstring>
#include <istream>
#include <ostream>
#ifndef STRING_H_O
#define STRING_H_O 1

class string {
    typedef ::iter<char> iter;

public:
    string() { init(); }
    string(const char x) {
        init();
        *this = x;
    }
    template <size_t len>
    string(const char (&x)[len]) {
        init();
        *this = x;
    }
    string(const string &x) {
        init();
        *this = x;
    }
    string(int i, const char &x) {
        init();
        while (i) {
            *this += x;
            --i;
        }
    }
    ~string() { delete[] a; }

    //返回字符串长度
    size_t size() { return _LEN; }
    //判断字符串是否为空
    bool empty() {
        if (_LEN == 0) {
            return true;
        }
    }

    //返回begin迭代器
    iter begin() { return iter(a); }
    //返回end迭代器
    iter end() { return iter(a + _LEN); }

    //连接操作
    string operator+(const char x) {
        string re = *this;
        re.a[re._LEN] = x;
        if (re._LEN > re._CAP - 1) {
            re.a = al.expend(re.a, _CAP, 3);
        }
        re.a[++re._LEN] = '\0';
        return re;
    }
    //连接操作
    template <size_t len>
    string operator+(const char (&x)[len]) {
        string re = *this;
        if (x == NULL) {
            return re;
        }
        size_t n = len;
        if (re._LEN + n > re._CAP) {
            re.a = al.expend(re.a, _CAP, re._LEN + n - re._CAP);
        }
        memcpy(re.a + _LEN, x, n);
        re._LEN += n;
        return re;
    }
    //连接操作
    string operator+(const string &x) {
        string re = *this;
        if (x._LEN == 0) {
            return re;
        }
        size_t n = x._LEN;
        if (re._LEN + n > re._CAP) {
            re.a = al.expend(re.a, _CAP, re._LEN + n - re._CAP);
        }
        memcpy(re.a + _LEN, x.a, n);
        re._LEN += n;
        return re;
    }

    //连接操作
    void operator+=(const char x) {
        *this = this->operator+(x);
        return;
    }
    //连接操作
    template <size_t len>
    void operator+=(const char (&x)[len]) {
        *this = this->operator+(x);
        return;
    }
    //连接操作
    void operator+=(const string &x) {
        *this = this->operator+(x);
        return;
    }

    //赋值or初始化操作
    void operator=(const char x) {
        this->_LEN = 0;
        this->a[0] = '\0';
        this->operator+=(x);
        return;
    }
    //赋值or初始化操作
    template <size_t len>
    void operator=(const char (&x)[len]) {
        this->_LEN = 0;
        this->a[0] = '\0';
        this->operator+=(x);
        return;
    }
    //赋值or初始化操作
    void operator=(const string &x) {
        if (x._CAP > this->_CAP) {
            this->a = al.expend(this->a, _CAP, x._CAP - this->_CAP);
        }
        memcpy(this->a, x.a, x._LEN);
        this->_LEN = x._LEN;
        return;
    }

    /*使用下标返回字符串元素
     *支持负数逆序访问——x[-1]为最后一个元素
     */
    char &operator[](const int i) {
        if (i < 0) {
            return this->a[this->_LEN + i];
        }
        return this->a[i];
    }

    //定义使用流输入
    friend std::istream &operator>>(std::istream &in, string &x);
    //定义使用流输出
    friend std::ostream &operator<<(std::ostream &out, string &x);

private:
    char *a;
    size_t _CAP; //容量
    size_t _LEN; //当前字符串长度
    Allocator<char> al;

    //对字符串内存进行扩大
    void flash_vessel(int klen) {
        char *p = a;
        char *re = new char[_CAP + klen];
        memcpy(re, a, _LEN + 1);
        a = re;
        delete[] p;
        _CAP += klen;
    }

    //初始化
    void init() {
        _LEN = 0;
        _CAP = 20;
        a = new char[_CAP];
    }
};

std::istream &operator>>(std::istream &in, string &x) {
    int c;
    while (1) {
        //读取单个字符
        c = in.get();
        if (c == EOF) {
            break;
        }
        //遇空格、回车和tab键停止操作
        else if (c == 32 || c == '\n' || c == 9) {
            x.a[x._LEN] == '\0';
            break;
        }
        x.a[x._LEN] = c;
        if (x._LEN > x._CAP - 1) {
            x.flash_vessel(10);
        }
        ++x._LEN;
    }
    return in;
}
std::ostream &operator<<(std::ostream &out, string &x) {
    int i = 0;
    while (i < x._LEN) {
        out << x.a[i++];
    }
    return out;
}

void swap(char &a, char &b) {
    char t = a;
    a = b;
    b = t;
}
#endif