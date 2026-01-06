#include <iostream>
#include <string>
using namespace std;

struct Node {
    string vehicleNo;
    Node* next;
    Node(string v){
        vehicleNo = v;
        next = NULL;
    } 
};
class ParkingAreaQueue {
    Node* front;
    Node* rear;
    int capacity;
    int count;
public:
    ParkingAreaQueue(int size) {
        capacity = size;
        front = rear = nullptr;
        count = 0;
    }
    // Enqueue
    void arrive(string vehicleNo) {
        if (count == capacity) { // base case 
            cout << "Parking full!"<<endl;
            return;
        }
        Node* newNode = new Node(vehicleNo);
        if (rear == nullptr) { // empty node case 
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
        cout << "Vehicle"<<vehicleNo<<"parked successfully."<<endl;
    }

    void depart(){
        if(front==NULL){
            cout<<"Parking Empty!"<<endl;
            rear = NULL;
        }else{
            Node*temp = front;
            temp = temp->next;
            delete temp;
            count --;

        }
    }
};
int main(){
    return 0;
}