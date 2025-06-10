#include <iostream>
#define MAX 4
using namespace std;
 int arr[MAX];
int front=-1, rear=-1;


void enqueue(int a) {
    if(front==0 && rear==MAX-1) {
        cout << "Queue is full" << endl;
        return;
    }
    else if(front==-1 && rear==-1){
        front = rear = 0; 
    } else if(rear == MAX - 1 && front != 0) {
        rear = 0; 
    } else {
        rear =rear+1; 
    }
    arr[rear] = a;
}

int dequeue() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return -1;
    }

    int value = arr[front];
    if (front == rear) {
        front = rear = -1; 
    } else {
        front = (front + 1) % MAX;
    }
    return value;
}

int main(){
    int choice, value;
    while(true){
        cout << "1. Enqueue\n2. Dequeue\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if(value != -1) {
                    cout << "Dequeued value: " << value << endl;
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}