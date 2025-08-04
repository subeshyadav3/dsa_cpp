#include <stdio.h>

#define MAX 100

struct Node {
    int data;
    int next;
    int prev;
};

struct Node list[MAX];
int head = -1;
int freeIndex = 0;

int getFreeNode() {
    if (freeIndex >= MAX) return -1;
    list[freeIndex].next = -1;
    list[freeIndex].prev = -1;
    return freeIndex++;
}

void insertAtBeginning(int value) {
    int newNode = getFreeNode();
    if (newNode == -1) return;

    list[newNode].data = value;
    list[newNode].next = head;
    list[newNode].prev = -1;

    if (head != -1) list[head].prev = newNode;
    head = newNode;
}

void insertAtEnd(int value) {
    int newNode = getFreeNode();
    if (newNode == -1) return;

    list[newNode].data = value;
    list[newNode].next = -1;

    if (head == -1) {
        list[newNode].prev = -1;
        head = newNode;
        return;
    }

    int temp = head;
    while (list[temp].next != -1) temp = list[temp].next;

    list[temp].next = newNode;
    list[newNode].prev = temp;
}

void insertAfter(int prevValue, int value) {
    int temp = head;
    while (temp != -1 && list[temp].data != prevValue) temp = list[temp].next;
    if (temp == -1) return;

    int newNode = getFreeNode();
    if (newNode == -1) return;

    list[newNode].data = value;
    list[newNode].next = list[temp].next;
    list[newNode].prev = temp;

    if (list[temp].next != -1) list[list[temp].next].prev = newNode;
    list[temp].next = newNode;
}

void deleteFromBeginning() {
    if (head == -1) return;
    int temp = head;
    head = list[head].next;
    if (head != -1) list[head].prev = -1;
}

void deleteFromEnd() {
    if (head == -1) return;
    int temp = head;
    while (list[temp].next != -1) temp = list[temp].next;

    if (list[temp].prev != -1) {
        list[list[temp].prev].next = -1;
    } else {
        head = -1;
    }
}

void deleteAfter(int value) {
    int temp = head;
    while (temp != -1 && list[temp].data != value) temp = list[temp].next;
    if (temp == -1 || list[temp].next == -1) return;

    int delNode = list[temp].next;
    list[temp].next = list[delNode].next;
    if (list[delNode].next != -1) list[list[delNode].next].prev = temp;
}

void display() {
    int temp = head;
    while (temp != -1) {
        printf("%d <-> ", list[temp].data);
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
