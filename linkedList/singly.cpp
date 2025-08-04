#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtBeginning(int value) {
    Node* temp = new Node{value, head};
    head = temp;
}

void insertAtEnd(int value) {
    Node* temp = new Node{value, nullptr};
    if (!head) {
        head = temp;
        return;
    }
    Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = temp;
}

void insertAfter(int key, int value) {
    Node* curr = head;
    while (curr && curr->data != key) curr = curr->next;
    if (curr) {
        Node* temp = new Node{value, curr->next};
        curr->next = temp;
    }
}

void insertBefore(int key, int value) {
    if (!head) return;
    if (head->data == key) {
        insertAtBeginning(value);
        return;
    }
    Node* curr = head;
    while (curr->next && curr->next->data != key) curr = curr->next;
    if (curr->next) {
        Node* temp = new Node{value, curr->next};
        curr->next = temp;
    }
}

void insertAtPosition(int pos, int value) {
    if (pos <= 1) {
        insertAtBeginning(value);
        return;
    }
    Node* curr = head;
    for (int i = 1; i < pos - 1 && curr; ++i)
        curr = curr->next;
    if (curr) {
        Node* temp = new Node{value, curr->next};
        curr->next = temp;
    }
}

void deleteFromBeginning() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* curr = head;
    while (curr->next->next) curr = curr->next;
    delete curr->next;
    curr->next = nullptr;
}

void deleteAfter(int key) {
    Node* curr = head;
    while (curr && curr->data != key) curr = curr->next;
    if (curr && curr->next) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
}

void deleteFromPosition(int pos) {
    if (!head) return;
    if (pos == 1) {
        deleteFromBeginning();
        return;
    }
    Node* curr = head;
    for (int i = 1; i < pos - 1 && curr; ++i)
        curr = curr->next;
    if (curr && curr->next) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
}

void display() {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int choice, val, key, pos;
    while (true) {
        cout << "\nChoose an operation to perform:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Insert at Nth Position\n";
        cout << "6. Delete from Beginning\n";
        cout << "7. Delete from End\n";
        cout << "8. Delete After a Node\n";
        cout << "9. Delete from Nth Position\n";
        cout << "10. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cin >> val; insertAtBeginning(val); break;
            case 2: cin >> val; insertAtEnd(val); break;
            case 3: cin >> key >> val; insertAfter(key, val); break;
            case 4: cin >> key >> val; insertBefore(key, val); break;
            case 5: cin >> pos >> val; insertAtPosition(pos, val); break;
            case 6: deleteFromBeginning(); break;
            case 7: deleteFromEnd(); break;
            case 8: cin >> key; deleteAfter(key); break;
            case 9: cin >> pos; deleteFromPosition(pos); break;
            case 10: display(); break;
            case 0: return 0;
            default: break;
        }
    }
}
