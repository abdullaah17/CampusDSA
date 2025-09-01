#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    // O(1)
    cout << "Constant time example: " << n*n << endl;

    // O(n)
    cout << "Linear time example: ";
    for (int i = 0; i < n; i++) cout << i << " ";
    cout << endl;

    // O(n^2)
    cout << "Quadratic time example: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << i << "," << j << " ";
        cout << endl;
    }
    return 0;
}
