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

#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 100

void reverseExpression(char ch[]) {
    int len = strlen(ch);
    char temp;

    for (int i = 0; i < len / 2; i++) {
    
        char left = ch[i];
        char right = ch[len - i - 1];

        if (left == '(') left = ')';
        else if (left == ')') left = '(';

        if (right == '(') right = ')';
        else if (right == ')') right = '(';

        ch[i] = right;
        ch[len - i - 1] = left;
    }


    if (len % 2 == 1) {
        int mid = len / 2;
        if (ch[mid] == '(') ch[mid] = ')';
        else if (ch[mid] == ')') ch[mid] = '(';
    }
 
}

int main() {
    char infix[SIZE], post[SIZE];
    int i = 0, j = 0;
    cout << "Enter expression: ";
    cin >> infix;

    reverseExpression(infix);
    
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
    reverseExpression(post);
    cout << "Prefix  expression: " << post << endl;
    return 0;
}
