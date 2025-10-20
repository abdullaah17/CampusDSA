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
};

int main(){
    DoublyList l1;
    return 0;
}