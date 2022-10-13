#include<istream>
#include<ostream>
#ifndef STRING_H_O
#define STRING_H_O

class string{
private:
    char *a;
    size_t _cap;//容量
    size_t _len;//当前字符串长度

    //对字符串内存进行扩大
    void flash_vessel(int klen){
        char *p = a;
        char *re = new char[_cap + klen];
        memcpy(re, a, _len + 1);
        a = re;
        delete []p;
        _cap += klen;
    }

public:
    string(){
        _len = 0;
        _cap = 20;
        a = new char[_cap];
    }
    string(const char x){
        _len = 0;
        _cap = 20;
        a = new char[_cap];
        *this = x;
    }
    template<size_t len>
    string(const char(&x)[len]){
        _len = 0;
        _cap = 20;
        a = new char[_cap];
        *this = x;
    }
    string(const string &x){
        *this = x;
    }
    string(int i, const char &x){
        _len = 0;
        _cap = 20;
        a = new char[_cap];
        while(i){
            *this += x;
            --i;
        }
    }


    //返回字符串长度
    size_t size(){
        return _len;
    }
    //判断字符串是否为空
    bool empty(){
        if(_len == 0){
            return true;
        }
    }

    //连接操作
    string operator + (const char x){
        string re = *this;
        re.a[re._len] = x;
        if(re._len >= re._cap - 1){
            re.flash_vessel(5);
        }
        re.a[++re._len] = '\0';
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
        if(re._len + n >= re._cap){
            re.flash_vessel(re._len + n - re._cap);
        }
        while(1){
            re.a[re._len] = x[i];
            if(re.a[re._len] == '\0'){
                break;
            }
            ++re._len;
            ++i;
        }
        return re;
    }
    //连接操作
    string operator + (const string &x){
        string re = *this;
        size_t n = x._len;
        if(re._len + n >= re._cap){
            re.flash_vessel(re._len + n - re._cap);
        }
        for(size_t i = 0; i < n; ++i){
            re.a[re._len] = x.a[i];
            if(re.a[re._len] == '\0'){
                break;
            }
            ++re._len;
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
        this->_len = 0;
        this->a[0] = '\0';
        this->operator+=(x);
        return ;
    }
    //赋值or初始化操作
    template<size_t len>
    void operator = (const char(&x)[len]){
        this->_len = 0;
        this->a[0] = '\0';
        this->operator+=(x);
        return ;
    }
    //赋值or初始化操作
    void operator = (const string &x){
        this->a = x.a;
        this->_len = x._len;
        this->_cap = x._cap;
        return ;
    }


    //使用下标返回字符串元素
    char& operator [](const int i){
        if(i < 0){
            return this->a[this->_len + i];
        }
        return this->a[i];
    }


    //定义使用流输入
    friend std::istream & operator >> (std::istream &in, string &x);
    //定义使用流输出
    friend std::ostream & operator << (std::ostream &out, string &x);
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
            x.a[x._len] == '\0';
            break;
        }
        x.a[x._len] = c;
        if(x._len >= x._cap - 2){
            x.flash_vessel(10);
        }
        ++x._len;
    }
    return in;
}
std::ostream & operator << (std::ostream &out, string &x){
    int i = 0;
    while(i < x._len){
        out<<x.a[i++];
    }
    return out;
}
#endif