#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

int main(){
    Node *N1 = new Node(2);
    cout<<N1->data<<" "<<N1->next;
}