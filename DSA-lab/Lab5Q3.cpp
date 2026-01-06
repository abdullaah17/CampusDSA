#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    bool isEmergency;
    Patient* next; // points to the next patient

    Patient(int i, string n, int a, bool e) {
        id = i;
        name = n;
        age = a;
        isEmergency = e;
        next = nullptr;
    }
};

class HospitalQueue {
private:
    Patient* front;
    Patient* rear;
    int totalPatients;
    int emergencyCount;
    int regularCount;

public:
    HospitalQueue() {
        front = rear = nullptr;
        totalPatients = emergencyCount = regularCount = 0;
    }

    void enqueue(int id, string name, int age, bool isEmergency) {
        Patient* newPatient = new Patient(id, name, age, isEmergency);

        if (!front) { // If queue is empty
            front = rear = newPatient;
        } 
        else if (isEmergency) { 
            // Emergency patients go to the front
            newPatient->next = front;
            front = newPatient;
        } 
        else {
            // Regular patients go to the end
            rear->next = newPatient;
            rear = newPatient;
        }

        totalPatients++;
        if (isEmergency) emergencyCount++;
        else regularCount++;
    }

    void servePatient() {
        if (!front) {
            cout << "No patients to serve right now.\n";
            return;
        }

        Patient* temp = front;
        cout << "Serving Patient " << temp->name 
             << (temp->isEmergency ? " (Emergency)" : " (Regular)") << endl;

        front = front->next;
        if (!front) rear = nullptr; // if queue becomes empty

        totalPatients--;
        if (temp->isEmergency) emergencyCount--;
        else regularCount--;

        delete temp;
    }

    void displayQueue() {
        if (!front) {
            cout << "No patients waiting.\n";
            return;
        }

        cout << "\n--- Current Waiting List ---\n";
        Patient* temp = front;
        while (temp) {
            cout << "ID: " << temp->id 
                 << " | Name: " << temp->name 
                 << " | Age: " << temp->age 
                 << " | Type: " << (temp->isEmergency ? "Emergency" : "Regular") << endl;
            temp = temp->next;
        }
        cout << "-----------------------------\n";
    }

    void showStats() {
        cout << "\nTotal Patients: " << totalPatients << endl;
        cout << "Emergency: " << emergencyCount << endl;
        cout << "Regular: " << regularCount << endl;
    }
};

// Main function
int main() {
    HospitalQueue queue;

    queue.enqueue(1, "Ali", 25, false);
    queue.enqueue(2, "Sara", 40, true);
    queue.enqueue(3, "Hassan", 30, false);
    queue.enqueue(4, "Fatima", 22, true);

    queue.displayQueue();
    queue.showStats();

    cout << "\nNow serving patients...\n";
    queue.servePatient();
    queue.servePatient();

    queue.displayQueue();
    queue.showStats();

    return 0;
}
