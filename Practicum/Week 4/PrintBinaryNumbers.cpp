#include<iostream>
#include<queue>

void printBinaryNumbersUntil(int n) {
    std::queue<int> q;
    q.push(1); 
    // std::cout << q.front();
    for(int i = 1; i <= n; i += 1) {
        int currNum = q.front();
        q.pop();
        std::cout << currNum << std::endl;

        currNum *= 10;
        q.push(currNum);
        currNum += 1;
        q.push(currNum);
    }
}

int main() {
    int n;
    std::cin >> n;

    printBinaryNumbersUntil(n);
    return 0;
}

/*
1
10
11
100
101
110
111

*/