#ifndef STACK_H
#define STACK_H
#include<iostream>
using std::cout;

template<class T>class stack{
private:
    T val[20];
    int ptr = -1;
      
public:
    bool push(T v){
        if(ptr >= 20){
            return false;
        }
        val[++ptr] = v;
        return true;
    }
      
    bool pop(){
        if(ptr > -1){
            --ptr;
            return true;
        }
        return false;
    }
      
    int size(){
        return ptr + 1;
    }
      
    bool empty(){
        if(ptr > -1){
            return false;
        }
        else{
            return true;
        }
    }
      
    int top(){
        if(ptr == -1){
            return 0;
        }
        return val[ptr];
    }
      
    void print(){
        int q = ptr;
        while(q > -1){
            cout<<val[q];
            --q;
        }
    }
};
#endif
