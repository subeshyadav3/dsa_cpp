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
    int choice, data, ref, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Node\n";
        cout << "4. Insert Before Node\n";
        cout << "5. Insert at Position\n";
        cout << "6. Delete from Beginning\n";
        cout << "7. Delete from End\n";
        cout << "8. Delete After Node\n";
        cout << "9. Delete at Position\n";
        cout << "10. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                insertAtBeginning(head, data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                insertAtEnd(head, data);
                break;
            case 3:
                cout << "Enter data to insert after: ";
                cin >> ref;
                cout << "Enter new data: ";
                cin >> data;
                insertAfterNode(head, ref, data);
                break;
            case 4:
                cout << "Enter data to insert before: ";
                cin >> ref;
                cout << "Enter new data: ";
                cin >> data;
                insertBeforeNode(head, ref, data);
                break;
            case 5:
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter data: ";
                cin >> data;
                insertAtPosition(head, pos, data);
                break;
            case 6:
                deleteFromBeginning(head);
                break;
            case 7:
                deleteFromEnd(head);
                break;
            case 8:
                cout << "Enter data to delete after: ";
                cin >> ref;
                deleteAfterNode(head, ref);
                break;
            case 9:
                cout << "Enter position: ";
                cin >> pos;
                deleteAtPosition(head, pos);
                break;
            case 10:
                display(head);
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
