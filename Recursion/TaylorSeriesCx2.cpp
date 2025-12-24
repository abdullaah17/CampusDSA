#include<iostream>
using namespace std;

double e(int x, int n){ // Using Loop
    double s=1;
    int i;
    double num=1;
    double den=1;

    for (i=1; i<=n; i++){
        num*=x;
        den*=i;
        s+=num/den;
    }
    return s;
}

int main(){
    double r=e(1,10);
    cout<<r;
    return 0;
}