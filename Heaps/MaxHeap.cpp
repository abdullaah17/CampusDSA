// root > child   (MAX HEAP)
#include<iostream>
using namespace std;

// Helper functions
int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

// --------------------
// Insert in Max Heap
// --------------------
void insertMaxHeap(int heap[], int &size, int value) {
    heap[size] = value; // insert the value at the end first to complete the tree
    int i = size; // store the index
    size++; // increase the heap size 

    // Heapify Up:
    while (i > 0 && heap[parent(i)] < heap[i]) {
        // swaps till the parent element < newly inserted element
        swap(heap[i], heap[parent(i)]);
        i = parent(i); // move upward
    }
}

// --------------------
// Heapify Down (used in deletion)
// --------------------
void heapifyDown(int heap[], int size, int i) {
    int largest = i;
    int l = left(i);
    int r = right(i);
    // Compare root with children
    // check if left child is larger
    if (l < size && heap[l] > heap[largest])
        largest = l;

    // check if right child is larger
    if (r < size && heap[r] > heap[largest])
        largest = r;

    // if largest is not root
    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapifyDown(heap, size, largest); // continue heapify down
    }
}

// --------------------
// Delete / Extract Max
// --------------------
int deleteMax(int heap[], int &size) {

    if (size <= 0) {
        cout << "Heap is empty\n";
        return -1;
    }

    int root = heap[0];           // store max element (root)
    heap[0] = heap[size - 1];     // move last element to root
    size--;                       // reduce heap size

    // Heapify Down from root to restore heap property
    heapifyDown(heap, size, 0);

    return root;                  // return deleted element
}

// --------------------
// Print Heap
// --------------------
void printHeap(int heap[], int size) {
    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";
    cout << endl;
}

// --------------------
// Main Function
// --------------------
int main() {
    int heap[100];   // heap array
    int size = 0;    // current heap size

    // Insert elements
    insertMaxHeap(heap, size, 15); //[0]
    insertMaxHeap(heap, size, 20); //[1]
    insertMaxHeap(heap, size, 30); //[2]
    insertMaxHeap(heap, size, 40); //[3]
    insertMaxHeap(heap, size, 12); //[4]
    insertMaxHeap(heap, size, 25); //[5]

    cout << "Max Heap (array representation): ";
    printHeap(heap, size);

    // Delete max element
    cout << "Deleted element (max): " << deleteMax(heap, size) << endl;

    cout << "Heap after deletion: ";
    printHeap(heap, size);

    return 0;
}
