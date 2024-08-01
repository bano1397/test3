#include <iostream>
using namespace std;

int const STACKSIZE = 20; 

class Stack {
private:
    int StackArray[STACKSIZE];
    int Top;

public:
    Stack() {
        Top = -1;
    }

    bool IsEmpty() {
        return Top == -1;
    }

    bool IsFull() {
        return Top == STACKSIZE - 1;
    }

    int Size() {
        return Top + 1;
    }

    void Push(int value) {
        if(IsFull()) {
            cout << "Stack is Full\n";
        } else {
            StackArray[++Top] = value;
        }
    }

    void Pop() {
        if(IsEmpty()) {
            cout << "Stack is empty\n";
        } else {
            --Top;
        }
    }

    int TopElement() {
        if(IsEmpty()) {
            cout << "Stack is empty\n";
            return -1; 
        } else {
            return StackArray[Top];
        }
    }

    void Display() {
        if (IsEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        } else {
            for (int i = Top; i >= 0; i--) {
                cout << StackArray[i];
            }
            cout << endl;
        }
    }
};

void integer(int number) {
    Stack stk;
    while(number > 0) {
        int rem = number % 2; 
        number = number / 2;
        stk.Push(rem);
    }
    stk.Display();
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    integer(num);
    return 0;
}

