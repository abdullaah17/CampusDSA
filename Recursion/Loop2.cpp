// Comparing Loop with Head Recursion

#include<iostream>
using namespace std;

int i=1;
void fun(int n){
    while (i<=n){
        cout<<n;
        n++;
    }
}

int main(){
    int x=10;
    fun(x); // Output: 10-1
    return 0;
}

// It cannot be converted as it is.