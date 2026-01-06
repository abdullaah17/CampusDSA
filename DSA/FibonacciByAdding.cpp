#include <iostream>
using namespace std;

void f(int n){    
    cout << "Enter number of terms: ";
    cin >> n;

    int a = 0, b = 1;
    cout << "Fibonacci Series: " << a << " " << b << " ";

    for (int i = 2; i < n; i++) {  // loop starts from 2 as 0 and 1 are already printed
        int c = a + b;   // calculating the next Fibonacci number by adding 
        cout << c << " "; // prints it
        a = b;
        b = c; 
    }

}

int main() {
    f(5);
    return 0;
}
