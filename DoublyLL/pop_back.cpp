#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

class DoublyList{
    Node* head;
    Node* tail;
    public:
    DoublyList(){
        head = tail = NULL;
    }

    void pushFront(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }else{
            newNode->next = head; // connection between newNode and old head
            head->prev = newNode; // makes a connection between prev of old head and new node
            head = newNode; // new node is now new head
        }
    }
    void pushBack(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }else{
            newNode->prev = tail;
            tail->next = newNode->prev;
            tail = newNode;
        }
    }

    void popFront(){
        
        if (head==NULL){
            cout<<"Empty List"<<endl;
            return;
        }else{
        Node* temp = head; // stores the value of old head
        head = head->next; // head moves one node ahead
        head->prev=NULL; // prev of new head(old head) becomes null
        temp->next = NULL; // breaks the connection
        delete temp;
        }
    }

    void popBack(){
        
        if(head==NULL){
            cout<<"The Linked List is Empty"<<endl;
            return;
        }else{
        Node* temp = tail; // stores the old tail
        tail = tail->prev; // shifts tail backward
        tail->next=NULL;
          

        }
    void print(){
        Node* temp = head;
        while(temp!=NULL){
            cout<< temp->data<<"<=>";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    DoublyList l1;
    l1.pushFront(1);
    l1.pushFront(2);
    l1.pushFront(3);
    l1.pushFront(4);
    l1.popFront();
    l1.print();


    return 0;
}