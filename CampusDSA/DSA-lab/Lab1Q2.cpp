#include<iostream>
using namespace std;

class ArrayReverse{
    int arr[5];
    int n;
    public:
    ArrayReverse(){
    cout<<"Enter Number of Elements:";
    cin>> n;
    cout<<"Enter Elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    }
    void reverseArray(){
        int left = 0;
        int right = n-1 ;
        while (left<right){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left ++;
            right --;
        }
    }
    void display() {
        cout << "[ ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "]" << endl;
    }
};
int main(){
    ArrayReverse A1;
    A1.reverseArray();
    A1.display();
    return 0;
}