#include <iostream>
using namespace std;

class QuadraticProbing {
public:
    static const int size = 10;
    int table[size];

    QuadraticProbing() {
        for (int i = 0; i < size; i++) 
            table[i] = -1;
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);

        int i = 1;
        while (table[index] != -1) {
            index = (hashFunction(key) + i * i) % size;
            i++;

            if (i == size) {
                cout << "Hash Table Full!\n";
                return;
            }
        }
        table[index] = key;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << " : " << table[i] << endl;
    }
};

int main() {
    QuadraticProbing h;

    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(25);
    h.insert(35);

    h.display();

    return 0;
}
