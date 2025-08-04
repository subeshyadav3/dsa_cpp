#include <stdio.h>

#define MAX 100

struct Node {
    int data;
    int next;
};

struct Node list[MAX];
int head = -1;

void insertAtBeginning(int value) {
    int newNode = 0;
    while (list[newNode].next != -1 && newNode < MAX) newNode++;
    if (newNode >= MAX) return;

    list[newNode].data = value;
    list[newNode].next = head;
    head = newNode;
}

void insertAtEnd(int value) {
    int newNode = 0;
    while (list[newNode].next != -1 && newNode < MAX) newNode++;
    if (newNode >= MAX) return;

    list[newNode].data = value;
    list[newNode].next = -1;

    if (head == -1) {
        head = newNode;
        return;
    }

    int temp = head;
    while (list[temp].next != -1) {
        temp = list[temp].next;
    }
    list[temp].next = newNode;
}

void insertAfter(int prevValue, int value) {
    int temp = head;
    while (temp != -1 && list[temp].data != prevValue) {
        temp = list[temp].next;
    }
    if (temp == -1) return;

    int newNode = 0;
    while (list[newNode].next != -1 && newNode < MAX) newNode++;
    if (newNode >= MAX) return;

    list[newNode].data = value;
    list[newNode].next = list[temp].next;
    list[temp].next = newNode;
}

void deleteFromBeginning() {
    if (head == -1) return;
    head = list[head].next;
}

void deleteFromEnd() {
    if (head == -1) return;
    int temp = head;
    int prev = -1;
    while (list[temp].next != -1) {
        prev = temp;
        temp = list[temp].next;
    }
    if (prev == -1) {
        head = -1;
    } else {
        list[prev].next = -1;
    }
}

void deleteAfter(int value) {
    int temp = head;
    while (temp != -1 && list[temp].data != value) {
        temp = list[temp].next;
    }
    if (temp == -1 || list[temp].next == -1) return;
    int delNode = list[temp].next;
    list[temp].next = list[delNode].next;
}

void display() {
    int temp = head;
    while (temp != -1) {
        printf("%d -> ", list[temp].data);
        temp = list[temp].next;
    }
    printf("NULL\n");
}

int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAfter(20, 25);
    printf("List after insertions:\n");
    display();

    deleteFromBeginning();
    printf("List after deleting from beginning:\n");
    display();

    deleteFromEnd();
    printf("List after deleting from end:\n");
    display();

    deleteAfter(20);
    printf("List after deleting after 20:\n");
    display();

    return 0;
}
