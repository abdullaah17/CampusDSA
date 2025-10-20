#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Circular Queue class using Linked List
class CircularQueue {
    Node* front;
    Node* rear;
    int size;

public:
    CircularQueue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Add element to rear (enqueue)
    void push(int data) {
        Node* newNode = new Node(data);

        // If queue is empty
        if (front == nullptr) {
            front = rear = newNode;
            rear->next = front;  // circular link
        } else {
            rear->next = newNode; // link old rear to new node
            rear = newNode;       // move rear forward
            rear->next = front;   // maintain circular link
        }

        size++;
        cout << data << " added to circular queue.\n";
    }

    // Remove element from front (dequeue)
    void pop() {
        if (empty()) {
            cout << "Circular Queue Empty!\n";
            return;
        }

        // If there's only one element
        if (front == rear) {
            cout << "Removing " << front->data << "...\n";
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            cout << "Removing " << front->data << "...\n";
            front = front->next;     // move front ahead
            rear->next = front;      // maintain circular link
            delete temp;
        }

        size--;
    }

    // Peek the front element
    int peek() {
        if (empty()) {
            cout << "Circular Queue Empty!\n";
            return -1;
        }
        return front->data;
    }

    // Check if empty
    bool empty() {
        return front == nullptr;
    }

    // Get current size
    int getSize() {
        return size;
    }

    // Display queue elements (for clarity)
    void display() {
        if (empty()) {
            cout << "Circular Queue Empty!\n";
            return;
        }

        Node* temp = front;
        cout << "Circular Queue: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }

    // Destructor to free memory
    ~CircularQueue() {
        while (!empty()) {
            pop();
        }
    }
};

int main() {
    CircularQueue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.pop();
    q.display();

    q.push(40);
    q.display();

    q.pop();
    q.pop();
    q.pop();
    q.pop(); // should show empty message

    return 0;
}
