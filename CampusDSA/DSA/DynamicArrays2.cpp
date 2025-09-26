#include <iostream>
using namespace std;

int main(){
    int *a;
    int size;
    cin>>size;
    a = new int [size];
    for (int i=0; i<size;i++){
        cin>>a[i];
    }
    delete[]a;
}