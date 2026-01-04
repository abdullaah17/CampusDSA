#include <iostream>
using namespace std;

int p[30];

void readArray(int p[]) {
    cout << "Enter 30 elements:\n";
    for (int i = 0; i < 30; i++) {
        cin >> p[i];
    }
}

void findEvenSum(int p[]) {
    int evenSum = 0;
    for (int i = 0; i < 30; i++) {
        if (p[i] % 2 == 0) {
            evenSum += p[i];
        }
    }
    cout << "Sum of even numbers: " << evenSum << endl;
}

void searchThirdSmallest(int p[]) {
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;
    int thirdSmallest = INT_MAX;

    for (int i = 0; i < 30; i++) {
        if (p[i] < smallest) {
            thirdSmallest = secondSmallest;
            secondSmallest = smallest;
            smallest = p[i];
        }
        else if (p[i] < secondSmallest && p[i] != smallest) {
            thirdSmallest = secondSmallest;
            secondSmallest = p[i];
        }
        else if (p[i] < thirdSmallest && p[i] != smallest && p[i] != secondSmallest) {
            thirdSmallest = p[i];
        }
    }

    cout << "Third smallest element: " << thirdSmallest << endl;
}

int main() {
    readArray(p);
    findEvenSum(p);
    searchThirdSmallest(p);
    return 0;
}
