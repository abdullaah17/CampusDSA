#include<iostream>
#include<string>
using namespace std;

struct Car{
    string number;
    Car*next;
    Car(string number){
        this->number = number;
        this->next = NULL;
    }
};

class ParkingLotQueue{
    Car*front;
    Car*rear;
    int capacity;
    int count;
    public:
    ParkingLotQueue(int capacity){
        front = rear = NULL;
        this->capacity = capacity;
        count = 0;
    }
    bool isFull()  { return count == capacity; }
    bool isEmpty() { return count == 0; }

     void parkCar(string number) {
        if (isFull()) {
            cout << "Parking Full! Car " << number << " cannot enter.\n";
            return;
        }

        Car* newCar = new Car(number);

        if (isEmpty()) {
            front = rear = newCar;
            rear->next = front;
        } else {
            rear->next = newCar;
            rear = newCar;
            rear->next = front;
        }

        count++;
        cout << "Car " << number << "parked successfully.\n";
    }

    void leaveCar() {
    if (isEmpty()) {
        cout << "Parking lot empty.\n";
        return;
    }

    string leavingCar = front->number;

    if (front == rear) {  // only one car
        delete front;
        front = rear = NULL;
    } else {
        Car* temp = front;
        front = front->next;
        rear->next = front;
        delete temp;
    }

    count--;
    cout << "Car " << leavingCar << " left the parking.\n";
}

    void display(){
        if(isEmpty()){
            cout<<"Empty ParkingLot!"<<endl;
        }else{
            Car* temp = front;
            do{
                cout<<temp->number<<endl;
                temp = temp->next;
            }
            while(temp!=front);
            cout << "Total cars: " << count << "/" << capacity << endl;
        }
    } 
};
int main() {
    ParkingLotQueue lot(3);  // capacity 3 cars

    lot.parkCar("ABC-101");
    lot.parkCar("XYZ-202");
    lot.parkCar("LMN-303");
    lot.parkCar("JKL-404"); // this one won’t fit 

    lot.display();

    lot.leaveCar(); // first car leaves
    lot.parkCar("JKL-404"); // now it fits 

    lot.display();
}

