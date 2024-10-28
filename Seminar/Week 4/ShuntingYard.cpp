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
        std::cout << op << std::endl;
        throw std::runtime_error("unknown op");
    }
    return 0;
}

int getOperationValue(char operation) {
    switch(operation) {
        case '(':
            case ')':
                return 0;
        case '+':
            case '-':
                return 1;
        case '*':
            case '/':
                return 2; 
        default:
            // Throw error
            return -1;
    }
}

float solveExpression(std::string expression) {
    std::stack<float> values;
    std::stack<char> operations;
    for(char& currSymbol : expression) {
        if(isdigit(currSymbol)) {
            float currNum = (float)currSymbol-48;
            values.push(currNum);
        } else {
            if(currSymbol != '(' && !operations.empty()) {
                while(getOperationValue(operations.top()) >= getOperationValue(currSymbol)) {
                    if(getOperationValue(operations.top()) == 0) {
                        operations.pop();
                        break;
                    }
                
                    float end = values.top();
                    values.pop();
                    float start = values.top();
                    values.pop();
                    float newValue = do_op(operations.top(), start, end);
                    values.push(newValue);
                    
                    operations.pop();
                    if(operations.empty())
                        break;
                }
            }
            if(currSymbol != ')')
                operations.push(currSymbol);
        }
    }

    while(!operations.empty()) {
        if(operations.top() == '(') {
            operations.pop();
            continue;
        }
        float end = values.top();
        values.pop();
        float start = values.top();
        values.pop();

        float newValue = do_op(operations.top(), start, end);
        values.push(newValue);
        operations.pop();
    }
    return values.top();
}

int main() {

    std::cout << solveExpression("2+(3+4)*(6/3+4)+3");
    return 0;
}