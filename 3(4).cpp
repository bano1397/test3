#include <iostream>
#include <string>
using namespace std;

const int STACKSIZE = 100; 

class Stack {
private:
    char StackArray[STACKSIZE];
    int Top;

public:
    Stack() : Top(-1) {}

    bool IsEmpty() const {
        return Top == -1;
    }

    bool IsFull() const {
        return Top == STACKSIZE - 1;
    }

    int Size() const {
        return Top + 1;
    }

    void Push(char value) {
        if (!IsFull()) {
            Top++;
            StackArray[Top] = value;
        } else {
            cout << "Stack Overflow!" << endl;
        }
    }

    void Pop() {
        if (!IsEmpty()) {
            Top--;
        } else {
            cout << "Stack Underflow!" << endl;
        }
    }

    char TopElement() const {
        if (!IsEmpty()) {
            return StackArray[Top];
        } else {
            return '\0'; 
        }
    }
};

bool isBalanced(const string& expression) {
    Stack s;
    for (size_t i = 0; i < expression.length(); ++i) {
        char ch = expression[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            s.Push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.IsEmpty())
                return false;
            char top = s.TopElement(); 
            if ((ch == ')' && top == '(') ||
                (ch == ']' && top == '[') ||
                (ch == '}' && top == '{')) {
                s.Pop(); 
            } else {
                return false; 
            }
        }
    }
    return s.IsEmpty(); 
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (isBalanced(expression)) {
        cout << "The expression is balanced." << endl;
    } else {
        cout << "The expression is not balanced." << endl;
    }

    return 0;
}

