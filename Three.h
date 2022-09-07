#include<iostream>
#include<math.h>

struct Three{
    int one, two, three;
    Three(): one(0), two(0), three(0) {}
    Three(int a, int b, int c): one(a), two(b), three(c) {}

    void max_min(){
        std::cout<<"Max: "<<std::max(std::max(one, two), three)<<std::endl;
        std::cout<<"Min: "<<std::min(std::min(one, two), three);
    }
};
