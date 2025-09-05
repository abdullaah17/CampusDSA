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
void InsertAtHead(Node* &head, int value){
    Node* new_node = new Node(value); // Create New Node
    new_node -> next = head;
    head = new_node;
};

int main(){
    Node *N1 = new Node(2);
    cout<<N1->data<<" "<<N1->next;
}