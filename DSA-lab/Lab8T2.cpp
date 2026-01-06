#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    // Recursive search
    bool searchRec(Node* node, int key) {
        if (node == nullptr) return false;
        if (node->data == key) return true;
        if (key < node->data) return searchRec(node->left, key);
        else return searchRec(node->right, key);
    }

    // Recursive traversals
    void inorderRec(Node* node) {
        if (!node) return;
        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }

    void preorderRec(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }

    void postorderRec(Node* node) {
        if (!node) return;
        postorderRec(node->left);
        postorderRec(node->right);
        cout << node->data << " ";
    }

    // Find minimum node in subtree
    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    // Recursive delete
    Node* deleteRec(Node* node, int key) {
        if (node == nullptr) return node;

        if (key < node->data) {
            node->left = deleteRec(node->left, key);
        } else if (key > node->data) {
            node->right = deleteRec(node->right, key);
        } else {
            // node->data == key -> delete this node
            // Case 1: leaf
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // Case 2: one child
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
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

    // In-order traversal but only prints values <= X.
    // Uses BST property to prune branches.
    void displayLessOrEqualRec(Node* node, int X) {
        if (!node) return;
        // If node->data > X, then all nodes in node->right are > node->data (> X),
        // so skip right subtree and only explore left subtree.
        if (node->data <= X) {
            // left subtree might contain values <= X
            displayLessOrEqualRec(node->left, X);
            // current node is <= X
            cout << node->data << " ";
            // right subtree MAY contain values <= X, so explore it
            displayLessOrEqualRec(node->right, X);
        } else {
            // current node > X, so entire right subtree is > X — prune it.
            displayLessOrEqualRec(node->left, X);
        }
    }

public:
    BST() : root(nullptr) {}

    // Insert iteratively (duplicates go to the right)
    void insert(int val) {
        Node* newNode = new Node(val);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        Node* current = root;
        Node* parent = nullptr;
        while (current) {
            parent = current;
            if (val < current->data) current = current->left;
            else current = current->right;
        }
        if (val < parent->data) parent->left = newNode;
        else parent->right = newNode;
    }

    // Wrappers
    void inorder()    { inorderRec(root); }
    void preorder()   { preorderRec(root); }
    void postorder()  { postorderRec(root); }

    bool search(int key) { return searchRec(root, key); }

    void deleteValue(int key) { root = deleteRec(root, key); }

    void displayLessOrEqual(int X) {
        cout << "Elements <= " << X << ": ";
        displayLessOrEqualRec(root, X);
        cout << "\n";
    }
};

int main() {
    BST tree;
    int num;

    cout << "Enter non-negative integers to insert into BST.\n";
    cout << "Enter a negative number to stop input (negative number will NOT be inserted).\n";

    while (true) {
        cout << "Enter value: ";
        if (!(cin >> num)) { // input validation
            cout << "Invalid input. Exiting.\n";
            return 1;
        }
        if (num < 0) break;
        tree.insert(num);
    }

    cout << "\nTraversals of the BST:\n";
    cout << "In-order: ";
    tree.inorder();
    cout << "\nPre-order: ";
    tree.preorder();
    cout << "\nPost-order: ";
    tree.postorder();
    cout << "\n";

    // Search (recursive)
    cout << "\nEnter a number to SEARCH in the BST: ";
    int key;
    cin >> key;
    if (tree.search(key)) cout << key << " is FOUND in the BST.\n";
    else cout << key << " is NOT found in the BST.\n";

    // Delete
    cout << "\nEnter a number to DELETE from the BST: ";
    int del;
    cin >> del;
    tree.deleteValue(del);
    cout << "\nIn-order traversal after deletion: ";
    tree.inorder();
    cout << "\n";

    // Display_less functionality
    cout << "\nCall Display_less (show elements <= X).\n";
    cout << "Enter X: ";
    int X;
    cin >> X;
    tree.displayLessOrEqual(X);

    cout << "\nProgram finished.\n";
    return 0;
}
