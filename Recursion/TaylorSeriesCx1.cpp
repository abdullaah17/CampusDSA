#include<iostream>
using namespace std;

double e(int x, int n){ // Horner's Rule
    static double s = 1.0;
    if(n==0){
        return s;
    }
    s = 1 + (x * s) / n;
    return e(x, n-1);
}

int main(){
    double r=e(2,10);
    cout<<r;
    return 0;
}