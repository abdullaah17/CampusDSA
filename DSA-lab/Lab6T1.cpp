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
    // Dequeue
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

    // Display
    void display() {
        if (front == nullptr) {
            cout << "Parking is empty."<<endl;
            return;
        }
        cout << "Vehicles currently parked (front → rear):"<<endl;
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->vehicleNo << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter parking capacity: ";
    cin >> capacity;

    ParkingAreaQueue parking(capacity);
    int choice;
    string vehicleNo;

    do {
        cout << "1. Vehicle Arrive\n2. Vehicle Depart\n3. Display Parking 4. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter vehicle number: ";
                cin >> vehicleNo;
                parking.arrive(vehicleNo);
                break;
            case 2:
                parking.depart();
                break;
            case 3:
                parking.display();
                break;
            case 4:
                cout << "Exiting..."<<endl;
                break;
            default:
                cout << "Invalid choice!"<<endl;
        }
    } while (choice != 4);

    return 0;
}
