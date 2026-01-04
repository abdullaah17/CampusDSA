#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size){
    for (int i=0; i<size-1; i++ ){
        for(int j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void inserionSort(int arr[], int size){
    for (int i=1; i<size; i++){
        int key = arr[i];
        int j =i-1; // j becomes zero
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--; 
        }
        arr[j+1] = key;
    }
}

int main(){
    int size = 5;
    int arr[] = {23,43,98,65,12};
    bubbleSort(arr,size);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}