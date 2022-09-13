#include"Three.hpp"

int main(){
    Three* t = new Three(1, 2 ,3);
    t->max_min();
    delete t;
}