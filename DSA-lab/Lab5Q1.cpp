#include <iostream>
#include <string>
using namespace std;

class Person {
    int id;
    string name;
    int age;
public:
    Person() : id(0), name(""), age(0) {}

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
    }

    void output() const {
        cout << "\nUser Data:\n";
        cout << "Name: " << name << "\n";
        cout << "ID: " << id << "\n";
        cout << "Age: " << age << "\n";
    }
};

class Stack {
    struct Node {
        Person data;
        Node* next;
    };
    Node* head;
public:
    Stack() : head(NULL) {}

    bool isEmpty() { return head == NULL; }

    void push(const Person& p) {
        Node* newNode = new Node();
        newNode->data = p;
        newNode->next = head;
        head = newNode;
        cout << "Pushed!\n";
    }

    bool pop(Person& p) {
        if (isEmpty()) return false;
        Node* temp = head;
        p = head->data;
        head = head->next;
        delete temp;
        return true;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            temp->data.output();
            temp = temp->next;
        }
    }
};

class Queue {
    struct Node {
        Person data;
        Node* next;
        Node(const Person& p) : data(p), next(NULL) {}
    };
    Node* front;
    Node* rear;
public:
    Queue() : front(NULL), rear(NULL) {}

    bool isEmpty() { return front == NULL; }

    void addQueue(const Person& p) {
        Node* newNode = new Node(p);
        if (isEmpty()) front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Added to Queue!\n";
    }

    bool RemoveQueue(Person& p) {
        if (isEmpty()) return false;
        Node* temp = front;
        p = front->data;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
        return true;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front -> rear):\n";
        Node* temp = front;
        while (temp != NULL) {
            temp->data.output();
            temp = temp->next;
        }
    }
};

int main() {
    Stack st;
    Queue q;
    int choice;
    Person p;

    do {
        cout << "\n1) Push Stack\n2) Pop Stack\n3) Display Stack\n"
             << "4) Add Queue\n5) Remove Queue\n6) Display Queue\n0) Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                p.input();
                st.push(p);
                break;
            case 2:
                if (st.pop(p)) p.output();
                else cout << "Stack empty\n";
                break;
            case 3:
                st.display();
                break;
            case 4:
                p.input();
                q.addQueue(p);
                break;
            case 5:
                if (q.RemoveQueue(p)) p.output();
                else cout << "Queue empty\n";
                break;
            case 6:
                q.display();
                break;
            case 0:
                cout << "Bye\n";
                break;
            default:
                cout << "Invalid\n";
        }
    } while (choice != 0);

    return 0;
}
