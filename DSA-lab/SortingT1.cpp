#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int target){
    for(int i=0; i<n; i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}


int main(){
    int n, target;

    cout << "Enter number of elements in the array: ";
    cin >> n;
    int arr[n];

    cout<<"Enter Array:";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter Target:"<<endl;
    cin>>target;

    int result = linearSearch(arr,n,target);

    
    if (result != -1) {
        cout << "Element " << target << " found at index " << result << "." << endl;
    } else {
        cout << "Element " << target << " not found in the list." << endl;
    }
    return 0;
};