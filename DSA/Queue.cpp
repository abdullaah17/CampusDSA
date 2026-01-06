#include<iostream>
using namespace std;

class Queue{
    int *myArray;
    int size;
    int front, rear;

    Queue(int);
    bool isEmpty();
    bool isFull();
    void enqueue(int value);
    int dequeue();
    int getFront();
};
Queue::Queue(int s){
myArray = new int[s];
size = s;
front = -1;
rear = -1;
}
void Queue::enqueue(int value){
    if (isFull()){
        cout<<"Queue Overflow"<<endl;
        return;
    }else
    myArray[++rear] = value;
}
int Queue::dequeue(){
    if (isEmpty()){
        cout<<"Queue Underflow"<<endl;
        return -1;
}else
return myArray[++front];
}