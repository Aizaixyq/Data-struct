#include<istream>
#include<ostream>
#ifndef STRING_H_O
#define STRING_H_O

class string{
private:
    char *a;
    size_t _M;//容量
    size_t ptr;//当前字符串长度

    //对字符串内存进行扩大
    void flash_vessel(){
        char *p = a;
        char *re = new char[_M * 2];
        for(int i = 0; i < _M; ++i){
            re[i] = a[i];
        }
        a = re;
        delete []p;
        _M *= 2;
    }
    //检查边界决定是否需要扩容
    bool end_check(){
        if(this->ptr >= this->_M - 1){
            this->flash_vessel();
            return true;
        }
        return false;
    }

public:
    string(){
        ptr = 0;
        _M = 20;
        a = new char[_M];
    }
    string(const char *x){
        ptr = 0;
        _M = 20;
        a = new char[_M];
        *this = x;
    }
    string(const string &x){
        *this = x;
    }
    string(int i, const char &x){
        ptr = 0;
        _M = 20;
        a = new char[_M];
        while(i){
            *this += x;
            --i;
        }
    }
    //返回字符串长度
    size_t size(){
        return ptr;
    }
    //判断字符串是否为空
    bool empty(){
        if(ptr == 0){
            return true;
        }
    }

    //连接操作
    string operator + (const string &x){
        string re = *this;
        int n = x.ptr;
        for(int i = 0; i < n; ++i){
            re.a[re.ptr] = x.a[i];
            if(re.a[re.ptr] == '\0'){
                break;
            }
            else {
                re.end_check();
            }
            ++re.ptr;
        }
        return re;
    }
    //连接操作
    void operator += (const string &x){
        int n = x.ptr;
        for(int i = 0; i < n; ++i){
            this->a[this->ptr] = x.a[i];
            if(this->a[this->ptr] == '\0'){
                break;
            }
            else{
                this->end_check();
            }
            ++this->ptr;
        }
    }
    //连接操作
    string operator + (const char x){
        string re = *this;
        re.a[re.ptr] = x;
        re.end_check();
        re.a[++re.ptr] = '\0';
        return re;
    }
    //连接操作
    void operator += (const char x){
        this->a[this->ptr] = x;
        this->end_check();
        this->a[++this->ptr] = '\0';
        return ;
    }


    //赋值or初始化操作
    void operator = (const char *x){
        if(x == NULL){
            return ;
        }
        int i = 0;
        while(1){
            this->a[ptr] = x[i];
            if(this->a[ptr] == '\0'){
                break;
            }
            else{
                this->end_check();
            }
            ++this->ptr;
            ++i;
        }
    }
    //赋值or初始化操作
    void operator = (const string &x){
        this->a = x.a;
        this->ptr = x.ptr;
        this->_M = x._M;
    }
    //使用下标返回字符串元素
    char& operator [](int i){
        if(i < 0){
            return this->a[this->ptr + i];
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
            x.a[x.ptr] == '\0';
            break;
        }
        x.a[x.ptr] = c;
        x.end_check();
        ++x.ptr;
    }
    return in;
}
std::ostream & operator << (std::ostream &out, string &x){
    int i = 0;
    while(i < x.ptr){
        out<<x.a[i++];
    }
    return out;
}
#endif