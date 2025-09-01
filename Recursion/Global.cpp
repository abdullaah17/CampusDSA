#include<iostream>
using namespace std;

int x=0;  // Global Variable

int fun(int n){
    
    if(n>0){ 
        x++;
        return fun(n-1)+x;
        cout<<n<<endl;
    }
}

int main(){
    int r;
    r=fun(5);
    cout<<r; // Output:25, Same as the Static member
    return 0;
}