#include<iostream>
#include"string.hpp"

using std::cout;
using std::cin;

int main(){
    string a = "abc";
    a[-1] = 'a';
    a += 'a';
    string b;
    cin>>b;
    b += a; 
    cout<<b;
}