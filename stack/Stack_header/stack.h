#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int tos;
    int arr[100];
public:
    Stack();
    void push(char a);
    char pop();
    void displayStack();
};

#endif
