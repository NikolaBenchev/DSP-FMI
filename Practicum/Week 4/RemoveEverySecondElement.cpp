#include<iostream>
#include<queue>

std::queue<int> removeEverySecondElement(std::queue<int> q) {
    std::queue<int> result;
    for(int i = 0; !q.empty(); i++) {
        if(i % 2 == 0)
            result.push(q.front());
        q.pop();
    }
    return result;
}

int main() {
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q = removeEverySecondElement(q);

    while(!q.empty()) {
        std::cout << q.front() << std::endl;
        q.pop();
    }
    return 0;
}