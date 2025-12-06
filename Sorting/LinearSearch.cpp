#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={2,1,4,3,6};
    int n=5;
    int key = 2;
    int result = linearSearch(arr,n,key);
    cout<<result;

    return 0;
};