#include<iostream>
using namespace std;

int fun(int n){
    static int x=0;
    if(n>0){ 
        x++;
        return fun(n-1)+x;
        cout<<n<<endl;
    }
}

int main(){
    int r;
    r=fun(5);
    cout<<r; // Output:25, Without creating a static member the output would be 15

    // Calling the fun twice will give a different Output:

    r=fun(5);
    cout<<r;

    return 0;
}