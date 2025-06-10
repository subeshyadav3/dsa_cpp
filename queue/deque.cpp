#include <iostream>

#define MAX_SIZE 5 

using namespace std;

int arr[MAX_SIZE];
int front = -1, rear = -1;

void insertRear(int item) {
    if (rear == MAX_SIZE - 1) {
        cout << "Queue is full" << endl;
    } else {
        if (front == -1) { 
            front = 0;
        }
        rear = rear + 1;
        arr[rear] = item;
    }
}

void deleteFront() {
    if (front == -1 || front > rear) { 
        cout << "Queue is empty" << endl;
    } else {
        int item = arr[front];
        front = front + 1;
        if (front > rear) { 
            front = -1;
            rear = -1;
        }
    }
}

void insertFront(int item) {
    if (front == 0) {
        cout << "Queue is full at front" << endl;
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            front = front - 1;
        }
        arr[front] = item;
    }
}

void deleteRear() {
    if (front == -1 || front > rear) { 
        cout << "Queue is empty" << endl;
    } else {
        int item = arr[rear];
        rear = rear - 1;
        if (front > rear) { 
            front = -1;
            rear = -1;
        }
    }
}

void displayQueue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    displayQueue();

    deleteFront();
    displayQueue();

    deleteRear();
    displayQueue();

    insertFront(2);
    insertRear(30);
    displayQueue();

    deleteFront();
    deleteFront();
    deleteFront();
    displayQueue();
    deleteFront(); 

    return 0;
}