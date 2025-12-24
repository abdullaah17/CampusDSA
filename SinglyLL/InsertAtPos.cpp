#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void insertAtPosition(int val, int pos) {
        Node* newNode = new Node(val);

        // Case 1: Insert at head
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        // Traverse to (pos-1)th node
        for (int i = 1; temp != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }

        // If position is invalid
        if (temp == NULL) {
            cout << "Position out of range!\n";
            delete newNode;
            return;
        }

        // Insert node
        newNode->next = temp->next; // Connects the new node with the next node
        temp->next = newNode; // Connects the new node with the previous node
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    cout << "Original list: ";
    list.display();

    list.insertAtPosition(15, 2); // Insert 15 at position 2
    cout << "After inserting 15 at position 2: ";
    list.display();

    list.insertAtPosition(5, 1); // Insert 5 at head
    cout << "After inserting 5 at position 1: ";
    list.display();

    list.insertAtPosition(100, 10); // Invalid position
}
