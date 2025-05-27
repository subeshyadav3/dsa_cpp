#include <bits/stdc++.h>
using namespace std;

#define SIZE 100
int tos = -1;
char myStack[SIZE]; 

void push(char a) {
    if (tos >= SIZE - 1) {
        cout << "Stack Overflow!" << endl;
    } else {
        myStack[++tos] = a;
    }
}

char pop() {
    if (tos < 0) {
        cout << "Stack is Empty!" << endl;
        return '\0';
    } else {
        return myStack[tos--];
    }
}

int check_prec(char ch){
    if(ch=='^') return 3;
    if(ch=='*' || ch=='/') return 2;
    if(ch=='+' || ch=='-') return 1;
    return 0;
}

int main() {
    char infix[SIZE], post[SIZE];
    int i = 0, j = 0;
    cout << "Enter expression: ";
    cin >> infix;

    for(i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if(isalnum(ch)){
            post[j++] = ch;
        }
        else if(ch == '('){
            push(ch);
        }
        else if(ch == ')'){
            while(tos != -1) {
                char popped = pop();
                if(popped == '(') break;
                post[j++] = popped;
            }
        }
        else {
            while(tos != -1 && check_prec(ch) <= check_prec(myStack[tos])) {
                post[j++] = pop();
            }
            push(ch);
        }
    }
 

 
    while(tos != -1) {
        post[j++] = pop();
    }
    post[j] = '\0';

    cout << "Postfix expression: " << post << endl;
    return 0;
}
