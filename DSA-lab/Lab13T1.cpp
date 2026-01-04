#include <iostream>
using namespace std;

class HashTable {
    int *table;
    int size;
public:
    HashTable(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1; // -1 means empty slot
    }
    int hash(int key) {
        return key % size;
    }
    void insert(int key) {
        int index = hash(key);
        int originalIndex = index;
        while (table[index] != -1 && table[index] != -2) { // finds an empty slot(-1) and deleted slot(-2)
            index = (index + 1) % size; // moves to the next index
            if (index == originalIndex) { //when an occupied slot is found
                cout << "Hash Table is full, cannot insert " << key << endl;
                return;
            }
        }
        table[index] = key;
        cout << "Inserted " << key << " at index " << index << endl;
    }

    bool search(int key) {
        int index = hash(key);
        int originalIndex = index;

        while (table[index] != -1) {
            if (table[index] == key)
                return true;
            index = (index + 1) % size;
            if (index == originalIndex)
                break;
        }
        return false;
    }
    void remove(int key) {
        int index = hash(key);
        int originalIndex = index;
        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -2; // mark as deleted
                cout << "Deleted " << key << " from index " << index << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == originalIndex)
                break;
        }
        cout << key << " not found in hash table." << endl;
    }
    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < size; i++) {
            if (table[i] == -1)
                cout << i << ": [ ]" << endl;
            else if (table[i] == -2)
                cout << i << ": [Deleted]" << endl;
            else
                cout << i << ": [" << table[i] << "]" << endl;
        }
    }
};
int main() {
    HashTable ht(10); // Hash table of size 10

    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(25);

    ht.display();

    cout << "Searching 20: " << (ht.search(20) ? "Found" : "Not Found") << endl;
    cout << "Searching 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;

    ht.remove(20);
    ht.remove(15);

    ht.display();

    ht.insert(20); // Should properly reuse deleted slot
    ht.display();

    return 0;
}
