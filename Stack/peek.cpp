#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next=NULL;
};

class Stack{
    Node*top;
    public:
    Stack(){
        top=NULL;
    }
    void push(int val){
            Node* newNode = new Node();
            newNode-> data = val;
            newNode-> next = top;
            top = newNode;
            cout<<"Pushed Into Stack!"<<endl;
        }
        int pop(){
            if (top==NULL){
                cout<<"Stack is Empty!"<<endl;
            }else{
                int x = top->data;
                Node*temp = top;
                top = top->next;
                delete temp;
                return x;
            }
        }
        void peek(){
            if (top==NULL){
                cout<<"Stack is Empty!"<<endl;
            }else{
                cout<<top->data;
            }
        }
};

int main(){
    Stack S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.peek();
}