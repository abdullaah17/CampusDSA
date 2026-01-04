#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class HashTable {
public:
    static const int size = 10;
    Node* table[size];

    HashTable() {
        for (int i = 0; i < size; i++) {
            table[i] = nullptr;
        }
    }
    int hash(int key) {
        return key % size;
    }
    void insert(int key) {
        int index = hash(key);
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;

        cout << key << " inserted at index " << index << endl;
    }
    void display() {
        cout << "\nHash Table (Separate Chaining):\n";
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << " → ";

            Node* temp = table[i];
            int count = 0;

            if (!temp) {
                cout << "NULL (nodes: 0)";
            } else {
                while (temp) {
                    cout << temp->data;
                    temp = temp->next;
                    count++;
                    if (temp) cout << " → ";
                }
                cout << " (nodes: " << count << ")";
            }

            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice, val;

    while (true) {
        cout << "\n1. Insert\n2. Display\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            ht.insert(val);
            break;

        case 2:
            ht.display();
            break;

        case 3:
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
