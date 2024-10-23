#include<iostream>
#include<stack>

void print(std::stack<int> st) {
    while(!st.empty()) {
        std::cout<< st.top() << std::endl;
        st.pop();
    }
}

std::stack<int> reverse(std::stack<int> st) {
    std::stack<int> reverseSt;
    while(!st.empty()) {
        int curr = st.top();
        reverseSt.push(curr);
        st.pop();
    }

    return reverseSt;
}

int main() {
    std::stack<int> st;
    st.push(1);
    st.push(1);
    st.push(2);
    st.push(4);
    st.push(3);

    print(st);
    std::cout << std::endl;
    print(reverse(st));
    return 0;
}