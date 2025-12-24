// The famous McCarthy 91 function type
#include<iostream>
using namespace std;

int fun(int n){
    if (n>100){
        return n-10;
    }
    else {
        return fun(fun(n+11));
    }
}
int main(){
    int x=110;
    int r;
    r = fun(x);
    cout<<r;

    return 0;
}