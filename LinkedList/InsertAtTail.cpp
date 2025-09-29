#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this -> data=data;
        this -> next=NULL;
    }
};
void InsertAtTail(Node* &tail, int value){
    Node* new_node = new Node(value); // Create New Node
    tail -> next = new_node;
    tail = new_node;
};
void display(Node *head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"Null"<<endl;
}

int main(){
    Node *N1 = new Node(1);
    // Head and Tail both point to the first node initially
    Node* head = N1;
    Node* tail = N1;
    InsertAtTail(tail,4);
    display(head);
    
}