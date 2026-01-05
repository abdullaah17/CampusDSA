// root < child
#include<iostream>
using namespace std;

// Helper functions
int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void insertMinHeap(int heap[], int &size, int value) {
    heap[size] = value; // insert the value at the end first to complete the tree
    int i = size; // store the index
    size++; // increase the heap size 

// Heapify Up:
                          
    while (i > 0 && heap[parent(i)] < heap[i]) { // swaps till the parent element < newly inserted el
        swap(heap[i], heap[parent(i)]);
        i = parent(i); // Moves the pointer upward so heapify up can continue correctly.
    }
}

void printHeap(int heap[], int size) {
    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";
    cout << endl;
}
int main() {
    int heap[100];   // heap array
    int size = 0;    // current heap size

    // Insert elements
    insertMinHeap(heap, size, 15); //[0]
    insertMinHeap(heap, size, 20); //[1]
    insertMinHeap(heap, size, 30); //[2]
    insertMinHeap(heap, size, 40); //[3]
    insertMinHeap(heap, size, 12); //[4]
    insertMinHeap(heap, size, 25); //[5]


    // Print final heap
    cout << "Min Heap (array representation): ";
    printHeap(heap, size);

    return 0;
}
