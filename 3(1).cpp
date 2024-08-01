#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op){
    if(op == '+'||op == '-'){
        return 1;
    }
    if(op == '*'||op == '/'){
        return 2;
    }
    return 0;
}

string infixToPostfix(string infix){
    stack<char> st; 
    string postfix = "";
    
    for(int i = 0; i < infix.length(); i++){
        char e = infix[i];
        
        if(isalnum(e)){
            postfix += e;
        }
        else if(e == '('){
            st.push(e);
        }
        else if(e == ')'){
            while(!st.empty() && st.top() != '('){
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && precedence(e) <= precedence(st.top())){
                postfix += st.top();
                st.pop();
            }
            st.push(e);
        }
    }
    
    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }
    
    return postfix;
}

int main() {
    string infix = "a+b*c+(d*e+f)*g";
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}

