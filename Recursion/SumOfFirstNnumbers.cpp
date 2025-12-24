// Using Recursion
#include<iostream>
using namespace std;

int SumByRecursion(int n){    // First Approach
    if (n==0){
        return 0;
    }
    return SumByRecursion(n-1)+n;
}

int SumByIteration(int n){   // Second Approach
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum=sum+i;
    }
    return sum;
}

int SumByFormula(int n){    // Fastest Approach
    return n*(n+1)/2;
}
int main(){
    int r = SumByIteration(9);
    cout<<r;
    return 0;
}