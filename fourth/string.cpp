#include<iostream>
#include"string.hpp"

using std::cout;
using std::cin;

int main(){
    string a = "abc1234567890123456";
    a[-1] = 'a';
    a += "av";
    string b;
    cin>>b;
    b += a;
    cout<<b<<std::endl;
    a = "acc";
    cout<<a;
}