#include<iostream>
using namespace std;

int fact(int n){    // Factorial
if(n==0){
    return 1;
}
else return fact(n-1)*n;
}  

int nCrByFact(int n, int r){  // nCr by Factorial
    int num, den;
    num=fact(n);
    den=fact(r)*fact(n-r);

    return num/den;
}

int nCrbyRec(int n, int r){  // nCr by Recursion
    if (n==r || r==0){
        return 1;
    }
    else return nCrbyRec(n-1,r-1)+nCrbyRec(n-1,r);
}
int main(){
    cout<<nCrByFact(4,2);
}