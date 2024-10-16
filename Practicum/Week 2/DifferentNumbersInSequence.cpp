#include<iostream>
#include<bitset>

const int MAX_N = 1024;

int main() {
    int n;
    std::cin >> n;
    std::bitset<MAX_N> bset(0);
    for(int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        bset[a] = true;
    }
    std::cout << bset.count() << std::endl;
    return 0;
}