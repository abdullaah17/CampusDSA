#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int m, n, p;
    cout << "Enter dimensions (m n p): ";
    cin >> m >> n >> p;

    int** A = new int*[m];
    for (int i = 0; i < m; i++)
        A[i] = new int[n];

    int** B = new int*[n];
    for (int i = 0; i < n; i++)
        B[i] = new int[p];

    int** C = new int*[m];
    for (int i = 0; i < m; i++)
        C[i] = new int[p];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = rand() % 10 + 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            B[i][j] = rand() % 10 + 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    cout << "\nMatrix A:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << "\t";
        cout << endl;
    }
    cout << "\nMatrix B:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++)
            cout << B[i][j] << "\t";
        cout << endl;
    }
    cout << "\nMatrix C (A × B):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++)
            cout << C[i][j] << "\t";
        cout << endl;
    }
    for (int i = 0; i < m; i++) {
        delete[] A[i];
        delete[] C[i];
    }
    for (int i = 0; i < n; i++)
        delete[] B[i];

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
