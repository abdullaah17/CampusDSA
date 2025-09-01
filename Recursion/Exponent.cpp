#include<iostream>
using namespace std;

int power(int m, int n){  // First Approach 
    if(n==0){
        return 1;
    }
    return power(m,n-1)*m;
}

int power1(int m, int n){  // Faster and Better Approach
    if(n==0){
        return 1;
    }
    else if(n%2==0){
    return power1(m*m, n/2);
}
else return m*power1(m*m,(n-1/2));
}

int main(){
    int r=power(2,9);
    cout<<r;
    return 0;
}