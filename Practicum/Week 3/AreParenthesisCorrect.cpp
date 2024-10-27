#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

bool areParenthesisCorrect(std::string expression) {
    std::stack<char> st;

    std::vector<char> closingParenthesis = {')', '}', ']'};

    for(char& curr : expression) {
        if(std::find(closingParenthesis.begin(), closingParenthesis.end(), curr) != closingParenthesis.end()) {
            // if(st.top() != curr) {
            //     std::cout << st.top() << " " << curr << std::endl;
            //     return false;
            // }
            switch(curr) {
                case ')':
                    if(st.top() != '(')
                        return false;
                    break;

                case ']':
                    if(st.top() != '[')
                        return false;
                    break;
                case '}':
                    if(st.top() != '{')
                        return false;
                    break;
                default:
                    break;
            }
            st.pop();
        } else {
            st.push(curr);
        }
    }

    return st.size() == 0;
}

int main() {
    std::string expression = "([()()]){}";

    std::cout << (areParenthesisCorrect(expression) ? "Yes" : "No") << std::endl;

    return 0;
}