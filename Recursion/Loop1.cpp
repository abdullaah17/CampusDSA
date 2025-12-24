// Comparing Loop with Tail Recursion

#include<iostream>
using namespace std;

void fun(int n){
    while (n>0){
        cout<<n;
        n--;
    }
}

int main(){
    int x=10;
    fun(x); // Output: 10-1
    return 0;
}

// In terms of Time Complexity, both are same
// In terms of Space Cplexity, Loop is efficient