#include<iostream>
#include "Vector.hpp"

int main() {
    Vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(13);

    std::cout << v[1] << std::endl;
    return 0;
}