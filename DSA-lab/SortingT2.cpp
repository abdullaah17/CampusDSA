#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    int Scount = 0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                Scount ++ ;
            }
        }
    }
    cout<<"Total Swaps:"<<Scount<<endl;
}

int main(){
    int n;
    cout<<"Enter Array Size:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter Array:"<<endl;
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    bubbleSort(arr,n);
    cout<<"Sorted Array:"<<endl;
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }

};