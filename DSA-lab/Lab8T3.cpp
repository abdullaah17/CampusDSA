#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* left;
    Node* right;

    Node(const string& val) {
        data = val;
        left = right = nullptr;
    }
};

class StringBST {
private:
    Node* root;

    Node* insertRec(Node* node, const string& val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insertRec(node->left, val);
        } else if (val > node->data) {
            node->right = insertRec(node->right, val);
        } else {
            // Duplicate: ignoring insertion (you can change behavior if you want duplicates)
            // Do nothing and return node
        }
        return node;
    }

    void inorderRec(Node* node) const {
        if (!node) return;
        inorderRec(node->left);
        cout << node->data << "\n";
        inorderRec(node->right);
    }

    bool searchRec(Node* node, const string& key) const {
        if (!node) return false;
        if (node->data == key) return true;
        if (key < node->data) return searchRec(node->left, key);
        return searchRec(node->right, key);
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* deleteRec(Node* node, const string& key) {
        if (!node) return node;

        if (key < node->data) {
            node->left = deleteRec(node->left, key);
        } else if (key > node->data) {
            node->right = deleteRec(node->right, key);
        } else {
            // node->data == key -> delete this node
            // Case 1: no child
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            // Case 2: one child
            else if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: two children -> replace with inorder successor
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteRec(node->right, temp->data);
        }
        return node;
    }

    // Helper to free all nodes (used at program end)
    void freeRec(Node* node) {
        if (!node) return;
        freeRec(node->left);
        freeRec(node->right);
        delete node;
    }

public:
    StringBST() : root(nullptr) {}
    ~StringBST() { freeRec(root); }

    void insert(const string& val) { root = insertRec(root, val); }

    void displayInOrder() const {
        if (!root) {
            cout << "(tree is empty)\n";
            return;
        }
        inorderRec(root);
    }

    bool search(const string& key) const { return searchRec(root, key); }

    void deleteValue(const string& key) { root = deleteRec(root, key); }
};

int main() {
    StringBST tree;
    cout << "Enter strings to insert into the BST (type END or press Enter on empty line to stop):\n";

    string line;
    while (true) {
        cout << "Enter string: ";
        if (!std::getline(cin, line)) break; // EOF protection
        if (line.empty() || line == "END") break; // sentinel (not inserted)
        tree.insert(line);
    }

    cout << "\nStrings in BST (sorted order - in-order traversal):\n";
    tree.displayInOrder();

    // Search
    cout << "\nEnter a string to SEARCH: ";
    if (!getline(cin, line)) line = "";
    if (!line.empty()) {
        if (tree.search(line)) cout << "\"" << line << "\" is FOUND in the BST.\n";
        else cout << "\"" << line << "\" is NOT found in the BST.\n";
    } else {
        cout << "No search string entered. Skipping search.\n";
    }

    // Delete
    cout << "\nEnter a string to DELETE from the BST: ";
    if (!getline(cin, line)) line = "";
    if (!line.empty()) {
        tree.deleteValue(line);
        cout << "\nIn-order traversal AFTER deletion:\n";
        tree.displayInOrder();
    } else {
        cout << "No delete string entered. Skipping deletion.\n";
    }

    cout << "\nProgram finished.\n";
    return 0;
}
