#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        this->data = val;
        this->next = nullptr;
    }
};

void InsertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void InsertAtPosition(Node* &head, Node* &tail, int pos, int d) {
    if (pos == 1) {
        InsertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < pos - 1 && temp != nullptr) {
        temp = temp->next;
        count++;
    }

    // If inserting at the end
    if (temp == nullptr || temp->next == nullptr) {
        InsertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Created a new node
    Node* node1 = new Node(10);

    // head and tail point to node1
    Node* head = node1;
    Node* tail = node1;

    InsertAtHead(head, 20); 
    InsertAtHead(head, 30);
    InsertAtHead(head, 40);

    print(head);

    InsertAtTail(tail, 20);
    InsertAtTail(tail, 30);
    InsertAtTail(tail, 50);

    print(head);

    InsertAtPosition(head, tail, 2, 100);
    print(head);

    InsertAtPosition(head, tail, 18, 200);
    print(head);

    return 0;
}
