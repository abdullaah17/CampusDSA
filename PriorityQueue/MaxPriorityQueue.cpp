#include <iostream>
using namespace std;

#define MAX 100

class MaxPriorityQueue {
    int heap[MAX];
    int size;

public:
    MaxPriorityQueue() {
        size = 0;
    }
    
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void insert(int x) {
        heap[size] = x;
        int i = size;
        size++;

        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && heap[l] > heap[largest])
            largest = l;
        if (r < size && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    int deleteMax() {
        if (size <= 0) return -1;

        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
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
    MaxPriorityQueue pq;
    pq.insert(10);
    pq.insert(40);
    pq.insert(15);
    pq.insert(30);

    pq.display();
    cout << "Deleted: " << pq.deleteMax() << endl;
    pq.display();
}
