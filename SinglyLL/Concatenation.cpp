#include <iostream>
using namespace std;

// Struct for Node (simple data + pointer)
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// LinkedList class to handle all operations
class LinkedList {
public:
    Node* head;

    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Function to insert node at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to display list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Concatenate another list to this one
    void concatenate(LinkedList& other) {
        if (head == NULL) {
            head = other.head; // other.head is basically head of 2nd ll
            return;
        }
        if (other.head == NULL) {
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = other.head;
    }
};

int main() {
    LinkedList list1, list2;

    // Create first list: 1 -> 2 -> 3
    list1.insertAtEnd(1);
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);

    // Create second list: 4 -> 5 -> 6
    list2.insertAtEnd(4);
    list2.insertAtEnd(5);
    list2.insertAtEnd(6);

    cout << "List 1: ";
    list1.display();

    cout << "List 2: ";
    list2.display();

    // Concatenate list2 into list1
    list1.concatenate(list2);

    cout << "\nAfter Concatenation:\n";
    list1.display();

    return 0;
}
