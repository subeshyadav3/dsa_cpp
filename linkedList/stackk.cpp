#include <stdio.h>

#define MAX 100

struct Node {
    int data;
    int next;
};

struct Node stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        top++;
        stack[top].data = value;
        stack[top].next = top - 1;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int value = stack[top].data;
        top = stack[top].next;
        return value;
    }
}

void displayStack() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    int temp = top;
    while (temp != -1) {
        printf("%d -> ", stack[temp].data);
        temp = stack[temp].next;
    }
    printf("NULL\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    displayStack();
    printf("Popped: %d\n", pop());
    displayStack();
    return 0;
}
