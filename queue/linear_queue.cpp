#include <iostream>
#define MAX 4
using namespace std;
 int arr[MAX];
int front=-1, rear=-1;

void enqueue(int a){
    if(rear==MAX-1){
        cout << "Queue is full" << endl;
        return;
    }

    else if(front==-1){
        front=rear=0;
    }
    else {
        rear++;
    }
    arr[rear]=a;
}
int dequeue(){
    if(front==-1 || front >rear){
        cout << "Queue is empty" << endl;
        return -1;
    }
    return arr[front++];
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