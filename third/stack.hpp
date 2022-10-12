#include<iostream>
#ifndef STACK_H
#define STACK_H

template<class T>class stack{
private:
    T *vals;
    size_t ptr;
    size_t _M;

    //对数组内存进行扩大
    void flash_vessel(){
        T *p = vals;
        T *re = new T[_M * 2];
        for(int i = 0; i < _M; ++i){
            re[i] = vals[i];
        }
        vals = re;
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
    stack(){
        ptr = 0;
        _M = 20;
        vals = new T[_M];
    }
    stack(const stack &x){
        ptr = x.ptr;
        _M = x._M;
        vals = x.vals;
    }
    //元素入栈
    void push(T v){
        vals[ptr] = v;
        end_check();
        ++ptr;
    }
    //元素出栈
    void pop(){
        if(ptr > 0){
            --ptr;
            return ;
        }
    }
    //返回元素数量
    int size(){
        return ptr;
    }
    //判空
    bool empty(){
        if(ptr > 0){
            return false;
        }
        else{
            return true;
        }
    }
    //获取顶部元素 
    int top(){
        if(ptr <= 0){
            return 0;
        }
        return vals[ptr - 1];
    }
    //输出栈内全部元素
    void print(){
        int q = ptr;
        while(q > 0){
            std::cout<<vals[q - 1];
            --q;
        }
    }
};
#endif