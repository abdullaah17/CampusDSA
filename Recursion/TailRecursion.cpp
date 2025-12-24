#include<iostream>
using namespace std;

void fun(int n){
    if(n>0){
        cout<<n<<endl;
        fun(n-1);
    }
}

int main(){
    int x=10;
    fun(x); // Output: 10-1
    return 0;
}

// Definition: It processes everything at the time of calling not at the time of returning.