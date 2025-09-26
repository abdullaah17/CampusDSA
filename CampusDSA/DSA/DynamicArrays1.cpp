#include <iostream>
using namespace std;

int main(){
    int *a;
    int size = 5;
    a = new int [size];
    for (int i=0; i<size;i++){
        cin>>a[i];
    }
    delete[]a;
}