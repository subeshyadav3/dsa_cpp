#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack() {
    tos = -1;
}

void Stack::push(char a) {
    arr[++tos] = a;
}

char Stack::pop() {
    if (tos == -1) {
        cout << "Stack Underflow!" << endl;
        return '\0';
    }
    return arr[tos--];
}

void Stack::displayStack() {
    if (tos == -1) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = 0; i <= tos; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
