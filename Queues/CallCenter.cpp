#include<iostream>
#include<string>
using namespace std;

struct Call{
    string callerName;
    Call*next;
    Call(string callerName){
        this->callerName = callerName;
        this->next = NULL;
    }
};
class CallCenterQueue{
    Call*front;
    Call*rear;
    int count;
    int capacity;
    public:
    CallCenterQueue(int capacity){
        front = rear = NULL;
        int count = 0;
        this->capacity = capacity;
    }
    

    bool isFull(){
        return count == capacity;
    }
    bool isEmpty(){
        return count = 0;
    }
    void receiveCall(string callerName){
        if(isFull()){
            cout<<"Busy"<<endl;
        }
        else{
            Call* newCall = new Call(callerName);
            if(front == NULL){
                front = rear = newCall;
                rear = newCall;
                rear->next = front; // for circular connection
            }
            count ++;
        }
    }
    void attendCall(){
        if(isEmpty()){
            cout<<"No Calls Waiting"<<endl;
        }
        else if(front == rear){
                delete front;
                front = rear = NULL;
            }
            else{
                Call* temp = front;
                front = front->next;
                rear->next = front;
                delete temp;
            }
            count --;
        }
        void showQueue(){
            if(isEmpty()){
                cout<<"No calls!"<<endl;
            }else{
                Call*temp = front;
                do{
                    cout<<temp->callerName;
                    temp = temp->next;
                }while(temp!=front);
            }
        }
    };
int main(){
    CallCenterQueue Q1(3);
    Q1.receiveCall("Abd");
    Q1.showQueue();
    
    return 0;
}