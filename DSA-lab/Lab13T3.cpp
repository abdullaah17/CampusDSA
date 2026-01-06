#include <iostream>
#include <string>
using namespace std;
class DoubleHashing {
public:
    static const int size = 10;
    string table[size];
    bool deleted[size]; 
    DoubleHashing() {
        for (int i = 0; i < size; i++) {
            table[i] = "";
            deleted[i] = false;
        }
    }
    int asciiSum(const string &s) {
        int sum = 0;
        for (char c : s) sum += int(c);
        return sum;
    }
    int h1(const string &s) {
        return asciiSum(s) % size;
    }
    int h2(const string &s) {
        return (asciiSum(s) % (size - 1)) + 1;
    }
    void insert(const string &key) {
        int index = h1(key);
        int step = h2(key);
        for (int i = 0; i < size; i++) {
            int newIndex = (index + i * step) % size;
            if (table[newIndex] == "" || deleted[newIndex]) {
                table[newIndex] = key;
                deleted[newIndex] = false;
                cout << key << " inserted at index " << newIndex << endl;
                return;
            }
        }
        cout << "Hash table full! Can't insert " << key << endl;
    }
    int search(const string &key) {
        int index = h1(key);
        int step = h2(key);
        for (int i = 0; i < size; i++) {
            int newIndex = (index + i * step) % size;
            if (table[newIndex] == key) {
                return newIndex;
            }
            if (table[newIndex] == "" && !deleted[newIndex]) {
                return -1; 
            }
        }
        return -1;
    }
    void remove(const string &key) {
        int pos = search(key);
        if (pos == -1) {
            cout << key << " not found!" << endl;
        } else {
            table[pos] = "";
            deleted[pos] = true; 
            cout << key << " deleted from index " << pos << endl;
        }
    }
    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < size; i++) {
            cout << i << " : ";
            if (table[i] == "" && !deleted[i]) cout << "EMPTY";
            else if (table[i] == "" && deleted[i]) cout << "DELETED";
            else cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    DoubleHashing dh;
    int choice;
    string name;

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter name to insert: ";
                cin >> name;
                dh.insert(name);
                break;

            case 2:
                cout << "Enter name to search: ";
                cin >> name;
                int pos;
                pos = dh.search(name);
                if (pos == -1) cout << name << " not found!\n";
                else cout << name << " found at index " << pos << endl;
                break;

            case 3:
                cout << "Enter name to delete: ";
                cin >> name;
                dh.remove(name);
                break;

            case 4:
                dh.display();
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
