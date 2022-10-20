#include<istream>
#include<ostream>
#include<cstring>
#include"iter.hpp"
#ifndef STRING_H_O
#define STRING_H_O 1

class string{
public:
    typedef ::iter<char> iter;
    string(){
        _LEN = 0;
        _CAP = 20;
        a = new char[_CAP];
    }
    string(const char x){
        _LEN = 0;
        _CAP = 20;
        a = new char[_CAP];
        *this = x;
    }
    template<size_t len>
    string(const char(&x)[len]){
        _LEN = 0;
        _CAP = 20;
        a = new char[_CAP];
        *this = x;
    }
    string(const string &x){
        *this = x;
    }
    string(int i, const char &x){
        _LEN = 0;
        _CAP = 20;
        a = new char[_CAP];
        while(i){
            *this += x;
            --i;
        }
    }
    /*~string(){
        delete []a;
    }*/


    //返回字符串长度
    size_t size(){
        return _LEN;
    }
    //判断字符串是否为空
    bool empty(){
        if(_LEN == 0){
            return true;
        }
    }

    //返回begin迭代器
    iter begin(){
        return iter(a);
    }
    //返回end迭代器
    iter end(){
        return iter(a + _LEN);
    }


    //连接操作
    string operator + (const char x){
        string re = *this;
        re.a[re._LEN] = x;
        if(re._LEN > re._CAP - 1){
            re.flash_vessel(3);
        }
        re.a[++re._LEN] = '\0';
        return re;
    }
    //连接操作
    template<size_t len>
    string operator + (const char(&x)[len]){
        string re = *this;
        if(x == NULL){
            return re;
        }
        int n = len;
        int i = 0;
        if(re._LEN + n > re._CAP){
            re.flash_vessel(re._LEN + n - re._CAP);
        }
        while(1){
            re.a[re._LEN] = x[i];
            if(re.a[re._LEN] == '\0'){
                break;
            }
            ++re._LEN;
            ++i;
        }
        return re;
    }
    //连接操作
    string operator + (const string &x){
        string re = *this;
        size_t n = x._LEN;
        if(re._LEN + n > re._CAP){
            re.flash_vessel(re._LEN + n - re._CAP);
        }
        for(size_t i = 0; i < n; ++i){
            re.a[re._LEN] = x.a[i];
            if(re.a[re._LEN] == '\0'){
                break;
            }
            ++re._LEN;
        }
        return re;
    }


    //连接操作
    void operator += (const char x){
        *this = this->operator+(x);
        return ;
    }
    //连接操作
    template<size_t len>
    void operator += (const char(&x)[len]){
        *this = this->operator+(x);
        return ;
    }
    //连接操作
    void operator += (const string &x){
        *this = this->operator+(x);
        return ;
    }
    

    //赋值or初始化操作
    void operator = (const char x){
        this->_LEN = 0;
        this->a[0] = '\0';
        this->operator+=(x);
        return ;
    }
    //赋值or初始化操作
    template<size_t len>
    void operator = (const char(&x)[len]){
        this->_LEN = 0;
        this->a[0] = '\0';
        this->operator+=(x);
        return ;
    }
    //赋值or初始化操作
    void operator = (const string &x){
        this->a = x.a;
        this->_LEN = x._LEN;
        this->_CAP = x._CAP;
        return ;
    }


    /*使用下标返回字符串元素
    *支持负数逆序访问——x[-1]为最后一个元素
    */
    char& operator [](const int i){
        if(i < 0){
            return this->a[this->_LEN + i];
        }
        return this->a[i];
    }


    //定义使用流输入
    friend std::istream & operator >> (std::istream &in, string &x);
    //定义使用流输出
    friend std::ostream & operator << (std::ostream &out, string &x);

private:
    char *a;
    size_t _CAP;//容量
    size_t _LEN;//当前字符串长度


    //对字符串内存进行扩大
    void flash_vessel(int klen){
        char *p = a;
        char *re = new char[_CAP + klen];
        memcpy(re, a, _LEN + 1);
        a = re;
        delete []p;
        _CAP += klen;
    }

};

std::istream & operator >> (std::istream &in, string &x){
    int c;
    while(1){
        //读取单个字符
        c = in.get();
        if(c == EOF){
            break;
        }
        //遇空格、回车和tab键停止操作
        else if(c == 32 || c == '\n' || c == 9){
            x.a[x._LEN] == '\0';
            break;
        }
        x.a[x._LEN] = c;
        if(x._LEN > x._CAP - 1){
            x.flash_vessel(10);
        }
        ++x._LEN;
    }
    return in;
}
std::ostream & operator << (std::ostream &out, string &x){
    int i = 0;
    while(i < x._LEN){
        out<<x.a[i++];
    }
    return out;
}

void swap(char &a, char &b){
    char t = a;
    a = b;
    b = t;
}
#endif