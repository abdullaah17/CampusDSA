#include <iostream>
using namespace std;

class LinearProbing {
public:
    static const int size = 10;
    int table[size];

    LinearProbing() {
        for (int i = 0; i < size; i++) 
            table[i] = -1; // -1 = empty
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index] != -1) {
            index = (index + 1) % size;
            if (index == start) { 
                cout << "Hash Table Full!\n";
                return;
            }
        }
        table[index] = key;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index] != -1) {
            if (table[index] == key)
                return true;
            index = (index + 1) % size;
            if (index == start) break;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << " : " << table[i] << endl;
    }
};

int main() {
    LinearProbing h;

    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(25);
    h.insert(35);

    h.display();

    cout << "Search 25: " << (h.search(25) ? "Found" : "Not Found") << endl;

    return 0;
}
