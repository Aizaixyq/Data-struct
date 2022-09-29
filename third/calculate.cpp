#include<iostream>
#include<string>
#include"stack.hpp"
using std::cin;
using std::string;

bool is_num(char a){
    if(a >= '0' && a <= '9'){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    string ip;
    cin>>ip;
    stack<int> num;
    stack<char> sym;
    for(auto i:ip){
        if(is_num(i)){
            num.push(i - '0');
        }
        else{
            sym.push(i);
        }
    }
    num.print();
    sym.print();
}
