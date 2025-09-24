#include<iostream>
using namespace std;

int main(){
    int first = 10;
    int second = 20;
    int *ptr = &second;
    *ptr = 30;
    cout << first << " " << second << endl;

    return 0;
}