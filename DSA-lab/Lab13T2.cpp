#include <iostream>
using namespace std;
class HashTable {
    int *table;
    int size;
    int count; 
public:
    HashTable(int s) {
        size = s;
        count = 0;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1; 
    }
    int hash(int key) {
        return key % size;
    }
    double loadFactor() {
        return (double)count / size;
    }
    void insert(int key) {
        int index = hash(key);
        int i = 0;
        while (table[(index + i * i) % size] != -1 && table[(index + i * i) % size] != -2) {
            i++;
            if (i == size) {
                cout << "Hash Table is full, cannot insert " << key << endl;
                return;
            }
        }
        table[(index + i * i) % size] = key;
        count++;
        cout << "Inserted " << key << " at index " << (index + i * i) % size << endl;
        double lf = loadFactor();
        cout << "Current Load Factor: " << lf << endl;
        if (lf > 0.7)
            cout << "Warning: Rehashing Recommended!" << endl;
    }
    bool search(int key) {
        int index = hash(key);
        int i = 0;
        while (table[(index + i * i) % size] != -1) {
            if (table[(index + i * i) % size] == key)
                return true;
            i++;
            if (i == size)
                break;
        }
        return false;
    }
    void remove(int key) {
        int index = hash(key);
        int i = 0;
        while (table[(index + i * i) % size] != -1) {
            if (table[(index + i * i) % size] == key) {
                table[(index + i * i) % size] = -2; // mark as deleted
                count--;
                cout << "Deleted " << key << " from index " << (index + i * i) % size << endl;
                return;
            }
            i++;
            if (i == size)
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
    HashTable ht(10); // size 10
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(25);
    ht.insert(35);
    ht.insert(15);
    ht.display();
    cout << "Searching 25: " << (ht.search(25) ? "Found" : "Not Found") << endl;
    cout << "Searching 50: " << (ht.search(50) ? "Found" : "Not Found") << endl;
    ht.remove(20);
    ht.remove(50);
    ht.display();
    ht.insert(40); // triggers load factor check
    ht.display();
    return 0;
}
