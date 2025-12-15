#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class ListNode {
public:
    int value;
    ListNode* next;

    ListNode(int val) {
        value = val;
        next = NULL;
    }
};

class SeparateChainingHashTable {
private:
    ListNode* table[TABLE_SIZE];

    int hash(int key) {
        return key % TABLE_SIZE;
    }
public:
    SeparateChainingHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = NULL;
    }

    void insert(int key) {
        int index = hash(key);
        ListNode* newNode = new ListNode(key);

        if (table[index] == NULL) {
            table[index] = newNode;
        }
        else {
            ListNode* current = table[index];
            while (current->next != NULL)
                current = current->next;

            current->next = newNode;
        }
    }

    void search(int key) {
        int index = hash(key);
        ListNode* current = table[index];

        while (current != NULL) {
            if (current->value == key) {
                cout << "Key Found\n";
                return;
            }
            current = current->next;
        }
        cout << "Key Not Found\n";
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            ListNode* current = table[i];

            while (current != NULL) {
                cout << current->value << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    SeparateChainingHashTable hashTable;
    int n, value;

    cout << "Enter number of values: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        hashTable.insert(value);
    }

    cout << "\nHash Table:\n";
    hashTable.display();

    cout << "\nSearch a key: ";
    cin >> value;
    hashTable.search(value);

    return 0;
}
