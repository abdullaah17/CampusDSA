#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    int** arr = new int*[rows];
    int* cols = new int[rows];

    for (int i = 0; i < rows; i++) {
        cout << "Enter number of columns for row " << i << ": ";
        cin >> cols[i];
        arr[i] = new int[cols[i]];
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols[i]; j++)
            arr[i][j] = rand() % 50 + 1;

    cout << endl;
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        cout << "Row " << i << ": ";
        for (int j = 0; j < cols[i]; j++) {
            cout << arr[i][j] << " ";
            sum += arr[i][j];
        }
        cout << "→ Sum = " << sum << endl;
    }

    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
    delete[] cols;

    return 0;
}
