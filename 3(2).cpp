#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int Size = 100;

class Stack {
private:
    int stackArray[Size]; 
    int top;

public:
    Stack() : top(-1) {} 

    bool isEmpty() {
        return top == -1;
    }

    void push(int item) {
        if (top < Size - 1) {
            stackArray[++top] = item;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    int pop() {
        if (!isEmpty()) {
            return stackArray[top--];
        } else {
            cout << "Stack Underflow\n";
            return INT_MIN; 
        }
    }
};

class PostfixEvaluator {
public:
    int evaluatePostfix(const char* exp) {
        Stack stack;
        for (int i = 0; exp[i]; i++) {
            if (isdigit(exp[i])) {
                stack.push(exp[i] - '0'); 
            } else {
                int val1 = stack.pop();
                int val2 = stack.pop();
                switch (exp[i]) {
                    case '+': stack.push(val2 + val1); break;
                    case '-': stack.push(val2 - val1); break;
                    case '*': stack.push(val2 * val1); break;
                    case '/': stack.push(val2 / val1); break;
                }
            }
        }
        return stack.pop(); 
    }
};


int main() {
    PostfixEvaluator evaluator;
    const char exp[] = "6523+8*+3+*"; 
    cout << "Postfix evaluation: " << evaluator.evaluatePostfix(exp) << endl;
    return 0;
}

