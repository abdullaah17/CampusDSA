#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int data){
        this -> data=data;
        this -> next=NULL;
    }
};

class LinkedList{
    public:
    Node*head;
    LinkedList(){
        head=NULL;
    }

void InsertAtHead(int value){
    Node* new_node = new Node(value); // Create New Node
    new_node -> next = head; // makes a connection between new node and old head
    head = new_node; // changes the old head to new head which is the new node
}
void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    LinkedList l1;
    l1.InsertAtHead(1);
    l1.InsertAtHead(2);
    l1.InsertAtHead(3);
    l1.InsertAtHead(4);
    l1.print();
    
}