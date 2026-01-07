#include <iostream>
using namespace std;

#define MAX 100

class MinPriorityQueue {
    int heap[MAX];
    int size;

public:
    MinPriorityQueue() {
        size = 0; //Initializes an empty heap
    }
    //Index Helper Functions
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Insert element
    void insert(int x) {
        heap[size] = x; //Insert new element at the end of heap
        int i = size; //Store its index in i
        size++; // increases heap size

        while (i != 0 && heap[parent(i)] > heap[i]) { //compares the new element heap[i] with its parent
            swap(heap[i], heap[parent(i)]); //swaps with parent if parent>new el
            i = parent(i); //updates the index to the parent node after a swap
        }
    }

    // Heapify
    void heapify(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i); //Get left & right children

        if (l < size && heap[l] < heap[smallest]) //If left child exists AND is smaller 
            smallest = l; //update smallest
        if (r < size && heap[r] < heap[smallest]) //If right child exists AND is smaller 
            smallest = r; //update largest

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    // Delete minimum
    int deleteMin() {
        if (size <= 0) return -1;

        int root = heap[0]; //Store smallest element (root)
        heap[0] = heap[size - 1]; //Replace root with last element
        size--; //reduces heap size 
        heapify(0);

        return root;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MinPriorityQueue pq;
    pq.insert(10);
    pq.insert(5);
    pq.insert(20);
    pq.insert(2);

    pq.display();
    cout << "Deleted: " << pq.deleteMin() << endl;
    pq.display();
}
