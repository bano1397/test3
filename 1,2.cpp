#include <iostream>
using namespace std;

int const STACKSIZE = 5;

class Stack {
private:
    int StackArray[STACKSIZE];
    int Top;

public:
    Stack(){
    	Top = -1;
    }

    bool IsEmpty() {
    	if(Top == -1)
        return true;
        else
        return false;
    }

    bool IsFull() { 
	    if(Top == STACKSIZE-1)
        return true;
        else
        return false;
	}

    int Size() {
    	return Top + 1;
    }

    void Push(int value) {
        if(IsFull() == true){
            cout << "Can't insert Element because the Stack is Full\n";
        }
        else{
        	Top++;
            StackArray[Top] = value;
        }
	}

    void Pop() {
        if(IsEmpty() == true){
            cout << "Can't Pop Element because the Stack is empty\n";
        }
        else{
            Top--;
        }
	}

    void Display() {
        if (Top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        else{
        	for (int i = Top; i >= 0; i--) {
            cout << StackArray[i] << " ";
        }
        cout << endl;
		}
        
    }
};

int main() {
    Stack stk;
    stk.Push(100); 
	stk.Push(200); 
	stk.Push(300); 
	stk.Push(400); 
	stk.Push(500);    stk.Display();
    cout << "\nPoping..\n";
    stk.Pop();
    stk.Display();
    system("pause");
    return 0;
}

