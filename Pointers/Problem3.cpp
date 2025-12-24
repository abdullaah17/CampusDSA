#include<iostream>
using namespace std;

int main(){

    int first = 10;
    int *p = &first;
    cout<< (*p)++<<" "; // output will be 10 bec of post increment
    cout<<first<<endl;

    return 0;
}