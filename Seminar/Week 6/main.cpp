#include<iostream>
#include "LList.h"
#include "Allocator.h"


int main() {
    Allocator<LList<int>::Node> allocator;
    {
        LList<int> a(allocator);
        a.push_back(1);
        a.push_back(3);
        a.push_front(12);
        a.push_front(3);
        a.print();
    }
    std::cout << allocator.checkForLeaks() << std::endl;
}