#include<iostream>
using namespace std;

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){ // skips the first element on index 0 as we consider it sorted
        int curr = arr[i];
        int prev = i-1;

        while(prev>=0 && arr[prev] > curr){ // prev>=0 to stop the loop at index 0 as the loop is backward
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
        display(arr,n);
        cout<<endl;
    }
}



int main(){
    int arr[] = {1,3,2,5,4};
    int n = 5;
    insertionSort(arr,n);
    display(arr,n);
    return 0;
};