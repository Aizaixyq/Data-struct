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
    void flash_vessel(int len){
        char *p = a;
        char *re = new char[_cap + len];
        memcpy(re, a, _len);
        a = re;
        delete []p;
        _cap += len;
    }

public:
    string(){
        _len = 0;
        _cap = 20;
        a = new char[_cap];
    }
    string(const char *x){
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
    string operator + (const string &x){
        string re = *this;
        size_t n = x._len;
        if(re._len + n >= re._cap - 1){
            re.flash_vessel(re._len + n + 1 - re._cap);
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
    void operator += (const string &x){
        size_t n = x._len;
        if(this->_len + n >= this->_cap - 1){
            this->flash_vessel(this->_len + n + 1 - this->_cap);
        }
        for(size_t i = 0; i < n; ++i){
            this->a[this->_len] = x.a[i];
            if(this->a[this->_len] == '\0'){
                break;
            }
            ++this->_len;
        }
    }
    //连接操作
    string operator + (const char x){
        string re = *this;
        re.a[re._len] = x;
        if(re._len >= re._cap - 2){
            re.flash_vessel(5);
        }
        re.a[++re._len] = '\0';
        return re;
    }
    //连接操作
    void operator += (const char x){
        this->a[this->_len] = x;
        if(this->_len >= this->_cap - 2){
            this->flash_vessel(5);
        }
        this->a[++this->_len] = '\0';
        return ;
    }


    //赋值or初始化操作
    void operator = (const char *x){
        if(x == NULL){
            return ;
        }
        int n = sizeof(x);
        int i = 0;
        if(this->_len + n >= this->_cap - 1){
            this->flash_vessel(this->_len + n + 1 - this->_cap);
        }
        while(1){
            this->a[_len] = x[i];
            if(this->a[_len] == '\0'){
                break;
            }
            ++this->_len;
            ++i;
        }
    }
    //赋值or初始化操作
    void operator = (const string &x){
        this->a = x.a;
        this->_len = x._len;
        this->_cap = x._cap;
    }
    //使用下标返回字符串元素
    char& operator [](int i){
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