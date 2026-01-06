#include <iostream>
#include <fstream>  
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            file << temp->data << " -> ";
            temp = temp->next;
        }
        file << "NULL" << endl;
        file.close();
        cout << "Linked list saved to " << filename << endl;
    }
};

int main() {
    List ll;
    int value, choice;
    char cont;

    do {
        cout << "\nEnter 1 to insert at front, 2 to insert at back: ";
        cin >> choice;

        cout << "Enter value: ";
        cin >> value;

        if (choice == 1)
            ll.push_front(value);
        else if (choice == 2)
            ll.push_back(value);
        else
            cout << "Invalid choice!" << endl;

        cout << "Current list: ";
        ll.print();

        cout << "Do you want to add more? (y/n): ";
        cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    cout << "\nFinal list: ";
    ll.print();

    ll.saveToFile("output.txt");

    return 0;
}
