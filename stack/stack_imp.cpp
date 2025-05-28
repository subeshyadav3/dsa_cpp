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

void displayStack() {
    if (tos == -1) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = 0; i <= tos; i++) {
            cout << myStack[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    push('a');
    push('b');
    push('c');

    cout << "Popped element: " << pop() << endl;
    cout << "Popped element: " << pop() << endl;
    cout << "Popped element: " << pop() << endl;
    cout << "Popped element: " << pop() << endl;

    displayStack();
    
    if (tos == -1) {
        cout << "Stack is now empty." << endl;
    } else {
        cout << "Top element in stack: " << myStack[tos] << endl;
    }

    push('d');
    push('e');
    cout << "Top element after pushing more elements: " << myStack[tos] << endl;
    displayStack();
    return 0;

}