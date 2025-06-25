#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        exit(0);
    }
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertAtBeginning(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}


void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}


void insertAfterNode(Node* head, int afterData, int data) {
    Node* temp = head;
    while (temp && temp->data != afterData)
        temp = temp->next;
    if (!temp) {
        cout << "Node with data " << afterData << " not found.\n";
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}


void insertBeforeNode(Node*& head, int beforeData, int data) {
    if (!head) return;

    if (head->data == beforeData) {
        insertAtBeginning(head, data);
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;
    while (curr && curr->data != beforeData) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        cout << "Node with data " << beforeData << " not found.\n";
        return;
    }

    Node* newNode = createNode(data);
    prev->next = newNode;
    newNode->next = curr;
}


void insertAtPosition(Node*& head, int position, int data) {
    if (position <= 0) {
        cout << "Invalid position.\n";
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; ++i) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Position out of bounds.\n";
        return;
    }

    Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteFromBeginning(Node*& head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd(Node*& head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* prev = nullptr;
    Node* temp = head;
    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    delete temp;
}

void deleteAfterNode(Node* head, int afterData) {
    Node* temp = head;
    while (temp && temp->data != afterData) {
        temp = temp->next;
    }

    if (!temp || !temp->next) {
        cout << "Cannot delete after the given node.\n";
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

void deleteAtPosition(Node*& head, int position) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (position <= 0) {
        cout << "Invalid position.\n";
        return;
    }
    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    for (int i = 1; temp != nullptr && i < position; ++i) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Position out of bounds.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
}

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


int main() {
    Node* head = nullptr;

    insertAtBeginning(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtPosition(head, 2, 15);   
    insertAfterNode(head, 20, 25);  
    insertBeforeNode(head, 10, 5);   
    cout << "List after insertions:\n";
    display(head);

    deleteFromBeginning(head);
    deleteFromEnd(head);
    deleteAfterNode(head, 15);
    deleteAtPosition(head, 2);

    cout << "List after deletions:\n";
    display(head);

    return 0;
}
