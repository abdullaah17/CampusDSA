#include<iostream>
using namespace std;

class ArrayOps{
    int arr[5];
    public:
    ArrayOps(){
        cout<<"Enter Elements:";
        for(int i=0; i<5; i++){
        cin>>arr[i];
    }
}
int findLargest(){
    int largestElement = arr[0];
    for(int i=0; i<sizeof(arr) / sizeof(arr[0]); i++){
        if(arr[i] > largestElement){
            largestElement = arr[i];
        }
    }
    return largestElement;
}
int findSmallest(){
    int SmallestElement = arr[0];
    for(int i=0; i<sizeof(arr) / sizeof(arr[0]); i++){
        if(arr[i] < SmallestElement){
            SmallestElement = arr[i];
        }
    }
    return SmallestElement;
}
};
int main(){
    ArrayOps A1;
    cout<<"Largest="<<A1.findLargest()<<endl;
    cout<<"Smallest="<<A1.findSmallest();

    return 0;
}