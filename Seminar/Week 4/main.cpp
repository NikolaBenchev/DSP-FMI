#include<iostream>
#include<stack>
#include<ctype.h>

float do_op(char op, float a, float b)
{
    switch(op) {
    case '+':
       return a+b;
        break;
    case '-':
       return a-b;
        break;
    case '*':
       return a*b;
        break;
    case '/':
       return a/b;
        break;
    default:
        throw std::runtime_error("unknown op");
    }
    return 0;
}

float solveExpression(std::string expression) {
    std::stack<float> values;
    std::stack<char> operators;
    for(char& currSymbol : expression) {
        if(isdigit(currSymbol) || currSymbol == ')') {
            float currNum = (float)currSymbol-48;
            if(currSymbol == ')') {
                operators.pop();
                if(values.empty())
                    continue;
                currNum = values.top();
                values.pop();
            }
            while(!operators.empty()) {
                if(operators.top() == '(')
                    break;
                    
                float start = values.top(), end = currNum;
                values.pop();

                currNum = do_op(operators.top(), start, currNum);
                std::cout << start << operators.top() << end << "=" << currNum << std::endl;
                operators.pop();
            }
            values.push(currNum);
        } else {
            operators.push(currSymbol);
        }
    }
    while(!operators.empty()) {
        float end = values.top();
        values.pop();
        float start = values.top();
        values.pop();
        
        float newValue = do_op(operators.top(), start, end);
        std::cout << start << operators.top() << end << "=" << newValue << std::endl;
        values.push(newValue);    
        operators.pop();
    }
    return values.top();
}

int main() {

    // std::cout << (float)'1';
    std::cout << solveExpression("2+(3+4)*(6/3+4)+3");
    return 0;
}