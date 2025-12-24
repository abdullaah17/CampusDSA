#include<iostream>
#include<string>
using namespace std;

struct Job{
    string docName;
    int pages;
    Job*next;
    job(string docName, int pages){
        this->docName = docName;
        this->next = NULL;
        this->pages = pages;
    }
};
class PrinterQueue{
    Job*front;
    Job*rear;
    int count;
    int capacity;
    PrinterQueue(int capacity){
        front = rear = NULL;
        count = 0;
        this->capacity = capacity;
    }
    bool isFull(){
        return count == capacity;
    }
    bool isEmpty(){
        return count = 0;
    }
    void AddJob(string name, int pages){
        if(isFull()){
            cout<<"Full!"<<endl;
            return;
        }
        else if(isEmpty()){
            Job* newJob = new Job("Doctor",10);
            front = rear = newJob;
            rear = newJob;
            rear->next = newJob;
        }else{
            Job* newJob = new Job("Doctor",10);
            rear->next = newJob;
            rear = newJob;
            rear->next = front;
        }
        count ++;
        cout<<"Job Added!"<<endl;
    }

    void completeJob(){
        if(isEmpty()){
            cout<<"Empty Queue!"<<endl;
            return;
        }
        else if(front == rear){
            delete front;
            front = rear = NULL;
            }
            else{
                Job*temp = front;
                front = front->next;
                rear->next = front;
                delete temp;
            }
            count --;
            cout<<"Completed!"<<endl;
        }
    void showQueue(){
        if(isEmpty()){
            cout<<"Empty Queue!"<<endl;
            return;
        }
        else{
            Job* temp = front;
            do{
                cout<<"Doc Name:"<<temp->docName<<"Pages:"<<temp->pages;
                temp=temp->next;
            }
            while(temp != front);
            cout << "Total Jobs: "<< count;
        }
    }
};
int main(){
    return 0;
}