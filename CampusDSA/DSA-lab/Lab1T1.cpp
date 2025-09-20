#include<iostream>
using namespace std;

int p[30];

void readArray(int p[]){
    cout<<"Enter Elements: ";
    for(int i=0; i<30; i++){
        cin>>p[i];
    }
}

void findEvenSum(int p[]){
    int evenSum = 0;
    for(int i=0; i<30; i++){
        if(p[i]%2==0){
            evenSum += p[i];
        }
    }
    cout << "Sum of even numbers: " << evenSum << endl;
}

void searchThirdSmallest(int p[]){
    int Largest = p[0];
    int SecLargest = p[0];
    int ThirdLargest = p[0];
    
    for(int i=0; i<n; i++){
            if(arr[i]>Largest){
                SecLargest = Largest;
                Largest = arr[i];
            }
            else if(arr[i]>SecLargest && arr[i]<Largest){
                SecLargest = arr[i];
            }
        }

    }
}