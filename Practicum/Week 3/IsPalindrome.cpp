#include<iostream>
#include<stack>
#include<string>

bool isPalindrome(std::string expression) {
    std::stack<char> symbolStack;
    for(int i = 0; i < expression.length(); i++) {
        if(expression.length() % 2 == 1 && i == expression.length() / 2) {
            continue;
        } 
        if(i < expression.length() / 2) {
            symbolStack.push(expression[i]);
        }
        else {
            if(symbolStack.top() != expression[i]) {
                return false;
            }
            symbolStack.pop();
        }
    }

    return true;
}

int main() {
    std::string str = "aaab";
    std::cout << (isPalindrome(str) ? "Yes" : "No") << std::endl;
    return 0;
}