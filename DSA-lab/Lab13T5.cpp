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
    void remove(int key) {
        int index = hash(key);
        Node* temp = table[index];
        Node* prev = nullptr;
        while (temp != nullptr) {
            if (temp->data == key) {
                if (prev == nullptr) {
                    table[index] = temp->next;
                } 
                else {
                    prev->next = temp->next;
                }

                delete temp;
                cout << key << " deleted from index " << index << endl;
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        cout << key << " not found in its chain!" << endl;
    }
    void display() {
        cout << "\nHash Table (Separate Chaining):\n";

        for (int i = 0; i < size; i++) {
            cout << "Index " << i << " → ";

            Node* temp = table[i];
            int count = 0;

            if (temp == nullptr) {
                cout << "NULL (nodes: 0)";
            } else {
                while (temp != nullptr) {
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
    int choice, value;

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            ht.insert(value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            ht.remove(value);
            break;

        case 3:
            ht.display();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
