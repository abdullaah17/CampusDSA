#include<iostream>
using namespace std;
class CircularQueue
{
private:
    int arr[5];
    int front, rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
            return false;
    }
    bool isFull()
    {
        if (front==(rear+1)%5)
        {
            return true;
        }
        else
            return false;
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is Full\n";
        }
        // 5 6 7 12 13
        //Dequeue
        //10
        if (isEmpty())
        {
            rear = front = 0;
        }
        else
        {
            rear = (rear + 1) % 5;
            arr[rear] = val;
            cout << "\nValue added in Queue\n";
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is EMpty\n";
        }
        else
            cout << arr[++front];
    }
};
void main()
{
    CircularQueue q1;
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(12);
    q1.enqueue(17);
    q1.dequeue();
    q1.enqueue(19);
}