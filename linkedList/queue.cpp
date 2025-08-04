#include <stdio.h>

#define MAX 100

struct Node {
    int data;
    int next;
};

struct Node queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear].data = value;
    queue[rear].next = (rear + 1 < MAX) ? rear + 1 : -1;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int value = queue[front].data;
        front = queue[front].next;
        return value;
    }
}

void displayQueue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d -> ", queue[i].data);
    }
    printf("NULL\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    displayQueue();
    printf("Dequeued: %d\n", dequeue());
    displayQueue();
    return 0;
}
