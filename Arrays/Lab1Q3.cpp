#include<iostream>
using namespace std;

class ArrayAnalyzer{
    int arr[5];
    int n;
    int Largest = arr[0];
    int SecLargest = arr[0];

    public:
    ArrayAnalyzer(){
    cout<<"Enter Number of Elements:";
    cin>> n;
    cout<<"Enter Elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    }
    int findSecondLargest(){
        for(int i=0; i<n; i++){
            if(arr[i]>Largest){
                SecLargest = Largest;
                Largest = arr[i];
            }
            else if(arr[i]>SecLargest){
                SecLargest = arr[i];
            }
        }
        cout<<"Second Largest:"<<SecLargest;


    }
}