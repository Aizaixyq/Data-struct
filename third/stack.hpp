#include<iostream>
#include<cstring>
#ifndef STACK_H
#define STACK_H 1

template<class T>class stack{
private:
    T *vals;
    size_t _LEN;
    size_t _CAP;

    //对数组内存进行扩大
    void flash_vessel(){
        T *p = vals;
        T *re = new T[_CAP * 2];
        memcpy(re, vals, _CAP * sizeof(T));
        vals = re;
        delete []p;
        _CAP *= 2;
    }
    //检查边界决定是否需要扩容
    bool end_check(){
        if(this->_LEN >= this->_CAP - 1){
            this->flash_vessel();
            return true;
        }
        return false;
    }

public:
    stack(){
        _LEN = 0;
        _CAP = 15;
        vals = new T[_CAP];
    }
    stack(const stack &x){
        while(x._CAP > this->_CAP){
            this->flash_vessel();
        }
        memcpy(this->a, x.a, x._LEN);
        this->_LEN = x._LEN;
    }
    ~stack(){
        delete []vals;
    }

    //元素入栈
    void push(T v){
        vals[_LEN] = v;
        end_check();
        ++_LEN;
    }
    //元素出栈
    void pop(){
        if(_LEN > 0){
            --_LEN;
            return ;
        }
    }
    //返回元素数量
    int size(){
        return _LEN;
    }
    //判空
    bool empty(){
        if(_LEN > 0){
            return false;
        }
        else{
            return true;
        }
    }
    //获取顶部元素 
    int top(){
        if(_LEN <= 0){
            return 0;
        }
        return vals[_LEN - 1];
    }
    //输出栈内全部元素
    void print(){
        int q = _LEN;
        while(q > 0){
            std::cout<<vals[q - 1];
            --q;
        }
    }
};
#endif