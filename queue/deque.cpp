  
#include <iostream>
using namespace std;
#define MAX 5
int deque[MAX];
int front = -1, rear = -1;
void insert_front(int value) {
    if (front == 0 && rear == MAX - 1 || front == rear + 1) {
        cout << "Deque is full!" << endl;
    } else {
        if (front == -1) { 
            front = rear = 0;
        } else if (front == 0) { 
            front = MAX - 1;
        } else {
            front--;
        }
        deque[front] = value;
        cout << "Inserted at front: " << value << endl;
    }
}
void insert_rear(int value) {
    if (front == 0 && rear == MAX - 1 || front == rear + 1) {
        cout << "Deque is full!" << endl;
    } else {
        if (front == -1) { 
            front = rear = 0;
        } else if (rear == MAX - 1) { 
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = value;
        cout << "Inserted at rear: " << value << endl;
    }
}
void delete_front() {
    if (front == -1) {
        cout << "Deque is empty!" << endl;
    } else {
        cout << "Deleted from front: " << deque[front] << endl;
        if (front == rear) { 
            front = rear = -1;
        } else if (front == MAX - 1) { 
            front = 0;
        } else {
            front++;
        }
    }
}
void delete_rear() {
    if (front == -1) {
        cout << "Deque is empty!" << endl;
    } else {
        cout << "Deleted from rear: " << deque[rear] << endl;
        if (front == rear) { 
            front = rear = -1;
        } else if (rear == 0) { 
            rear = MAX - 1;
        } else {
            rear--;
        }
    }
}
void display() {
    if (front == -1) {
        cout << "Deque is empty!" << endl;
    } else {
        cout << "Deque elements: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << deque[i] << " ";
            }
        } else {
            for (int i = front; i < MAX; i++) {
                cout << deque[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << deque[i] << " ";
            }
        }
        cout << endl;
    }
}
int main() {
    int choice, value;
    do {
        cout << "1. Insert at front\n2. Insert at rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                insert_front(value);
                break;
            case 2:
                cout << "Enter value to insert at rear: ";
                cin >> value;
                insert_rear(value);
                break;
            case 3:
                delete_front();
                break;
            case 4:
                delete_rear();
                break;
            case 5:
                display();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
      