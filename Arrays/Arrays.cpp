#include<iostream>
using namespace std;

int main(){
    const int Size = 10;
    int arr[Size];

    cout<<"Enter"<<Size<<"number of Elements:";
    for(int i = 0; i < Size; i++){
        cin>>arr[i];
    }

    // Finding Max Min Values in an Array
    int maxVal = arr[0];  
    int minVal = arr[0];       // both initialised with the first element of Array

    for(int i=1; i<Size; i++){
        if(arr[i]> maxVal){
            maxVal = arr[i];
        }
        if(arr[i]< minVal){
            minVal = arr[i];
        }
    }
    // Finding Sum of an Array
    int sum = 0;
    for(int i=0; i<Size; i++){
        sum+=arr[i];
    }
    // Finding Average of an Array
    double avg = static_cast <double> (sum) / 2;

    // Finding Reverse of an Array
    for (int i = 0; i<Size/2; i++){
        int temp = arr[i];
        arr[i] = arr[Size - i -1];      //arr[Size - i -1] gives the excat mirror value 
        arr[Size-i-1] = temp;      
    }
        // Output results
    cout << "Max: " << maxVal<<endl;
    cout << "Min: " << minVal<<endl;
    cout << "Sum: " << sum<<endl;
    cout << "Average: " << avg<<endl;

    cout << "Reversed Array: "<<endl;
    for (int i = 0; i < Size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

