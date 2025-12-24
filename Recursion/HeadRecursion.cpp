#include<iostream>
using namespace std;

void fun1(int n){
    if(n>0){ 
        fun1(n-1);
        cout<<n<<endl;
    }
}

int main(){
    int x=10;
    fun1(x); // Output: 1-10
    return 0;
}

// Definition: It processes everything only at the time of returning not at the time of calling.