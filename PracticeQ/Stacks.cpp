#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
}
class Stack{
    Node*top;
    public:
    Stack(){
        top = nullptr;
    }
    void isEmpty(){return top == nullptr};

    void push(int val){
        Node* newNode = new Node(val);
        newNode->next=top;
        top = newNode;
    }
    void pop(){
        if(isEmpty()){
            return;
        }else {
            Node*temp = top;
            cout<<temp->data;
            top=top->next;
            temp delete;
        }
    }
    int peek(){
        if(isEmpty()){
            return;
        }else{
            cout<<top->data;
        }
    }
}

class Queue{
    Node*front;
    Node*rear;
    public:
    Queue(){
        front = rear = nullptr;
    }

    void isEmpty(){return front==nullptr;}

    void enqueue(int val){
        Node* newNode = new Node(val);
        if (isEmpty()){
            front=rear=newNode;
        }else{
            rear->next=newNode;
            rear=newNode;
            // rear->next=front;

        }   
    }
    void dequeue(){
        if(isEmpty()){
            return;
        }else{
            Node*temp = front;
            int value;
            value = temp->data;
            front=front->next;
            //rear->next = front;
            delete temp;
        }
    }
     void display() { 
        if (isEmpty()) { 
            cout << "Circular Queue is empty.\n"; 
            return; 
        } 
 
        cout << "Circular Queue elements: "; 
        Node* temp = front; 
        do { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } while (temp != front); 
        cout << endl; 
    }
};

int main() { 
    CircularQueue cq; 
    cq.enqueue(10); 
    cq.enqueue(20); 
    cq.enqueue(30); 
    cq.display(); 
 
    cq.dequeue(); 
    cq.display(); 
 
    cq.enqueue(40); 
    cq.enqueue(50); 
    cq.display(); 
 
    return 0; 
};