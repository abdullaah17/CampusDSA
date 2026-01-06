#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements (0–100): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    const int bucketCount = 10;
    int buckets[bucketCount][100]; 
    int bucketSize[bucketCount] = {0};

    for (int i = 0; i < n; i++) {
        int index = arr[i] / 10;
        buckets[index][bucketSize[index]++] = arr[i];
    }
    for (int i = 0; i < bucketCount; i++) {
        insertionSort(buckets[i], bucketSize[i]);
        cout << "Bucket " << i << ": ";
        for (int j = 0; j < bucketSize[i]; j++)
            cout << buckets[i][j] << " ";
        cout << endl;
    }
    cout << "Sorted array: ";
    for (int i = 0; i < bucketCount; i++)
        for (int j = 0; j < bucketSize[i]; j++)
            cout << buckets[i][j] << " ";

    return 0;
};
