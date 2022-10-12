#include<iostream>
#include<vector>
#ifndef STACK_H
#define STACK_H

template<class T>class stack{
private:
    std::vector<T> vals;
    int ptr = -1;
      
public:
    bool push(T v){
        //if(ptr >= 20){
            vals.emplace_back(v);
        //}
        //vals[++ptr] = v;
        ++ptr;
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
        return vals[ptr];
    }
      
    void print(){
        int q = ptr;
        while(q > -1){
            std::cout<<vals[q];
            --q;
        }
    }
};
#endif