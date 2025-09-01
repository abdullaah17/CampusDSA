#include<iostream>
using namespace std;

int fib1(int n){  // Using Loops
    int t0, t1, s;
    if(n<=1){
        return n;
    }
    for (int i=2; i<=n; i++){
        s=t0+t1;
        t0=t1;
        t1=s;
        return s;
    }
}

int fib2(int n){
    if(n<=1){
        return n;
    }
    return fib2(n-2)+fib2(n-1);
}
int fib3(int n){
    int F[10];
    if(n<=1){
        F[n]=n;
        return n;
    }
    else {
        if(F[n-2]==-1)
        F[n-2]=fib3(n-2);
        
        if(F[n-1]==-1)
        F[n-1]=fib3(n-1);
        
        return F[n-2]+F[n-1];
    }
}
int main(){
    int r;
    r=fib3(5);
    cout<<r;
    return 0;
}