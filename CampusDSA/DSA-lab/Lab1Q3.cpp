#include<iostream>
using namespace std;

class ArrayAnalyzer{
    int arr[5];
    int n;
    int Largest;
    int SecLargest;

    public:
    ArrayAnalyzer(){
    cout<<"Enter Number of Elements:";
    cin>> n;
    cout<<"Enter Elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Largest = arr[0];
    SecLargest = arr[0];
    }
    int findSecondLargest(){
        Largest = arr[0];
        SecLargest = arr[0];

        for(int i=0; i<n; i++){
            if(arr[i]>Largest){
                SecLargest = Largest;
                Largest = arr[i];
            }
            else if(arr[i]>SecLargest && arr[i]<Largest){
                SecLargest = arr[i];
            }
        }
        cout<<"Second Largest:"<<SecLargest<<endl;

    }
    void display() {
        if (Largest == SecLargest) {
            cout << "Second Largest does not exist" << endl;
        } else {
            cout << "Second Largest = " << SecLargest << endl;
        }
    }
};

int main(){
    ArrayAnalyzer A1;
    A1.findSecondLargest();
    A1.display();
    return 0;
}