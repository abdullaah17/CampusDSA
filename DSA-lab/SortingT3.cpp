#include<iostream>
using namespace std;

void display(int arr[], int n);

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int smallestIdx = i; // considers first element the smallest
        for(int j=i+1; j<n; j++){ // starts from the second element
            if(arr[j] < arr[smallestIdx]){ // conpares the second element with the first(smallest)
                smallestIdx = j; // updates if a smaller element is found
            }
        }
        swap(arr[i],arr[smallestIdx]);
        display(arr,n);
        cout<<endl;
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