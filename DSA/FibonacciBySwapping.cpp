#include <iostream>
using namespace std;

void f(int n)
{
    cout << "Enter number of terms: ";
    cin >> n;

    int a = 0, b = 1;
    cout << "Fibonacci Series: " << a << " " << b << " ";

    for (int i = 2; i < n; i++) {
        b = a + b;    // calculate the next Fibonacci number and store it in b
        a = b - a;    // a stores the old b
        cout << b << " ";
    }
}
int main() {
    f(5);
    return 0;
}
