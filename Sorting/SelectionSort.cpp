#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int smallestIdx = i; // considers first element the smallest
        for(int j=i+1; j<n; j++){ // starts from the second element
            if(arr[j] < arr[smallestIdx]){ // conpares the second element with the first(smallest)
                smallestIdx = j; // swaps if condition matches
            }
        }
        swap(arr[i],arr[smallestIdx]);
    }
}
void display(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n = 5;
    int arr[]= {4,1,3,2,5};
    selectionSort(arr,n);
    display(arr,n);
    return 0;
}