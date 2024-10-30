#include<iostream>
#include<queue>
#include<stack>

std::queue<int> reverseKElements(int k, std::queue<int> q) {
    std::stack<int> st;
    for(int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    std::queue<int> result;
    while(!st.empty()) {
        result.push(st.top());
        st.pop();
    }

    while(!q.empty()) {
        result.push(q.front());
        q.pop();
    }

    return result;
}

void print(std::queue<int> q) {
    while(!q.empty()) {
        std::cout << q.front() << std::endl;
        q.pop();
    }
}


int main() {
    std::queue<int> q;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int curr;
        std::cin >> curr;
        q.push(curr);
    }

    int k;
    std::cin >> k;
    print(reverseKElements(k, q));
    return 0;
}