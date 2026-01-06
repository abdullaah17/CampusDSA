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
    bool searchRec(Node* root, int key) {
        if (root == nullptr)
            return false;
        if (root->data == key)
            return true;
        else if (key < root->data)
            return searchRec(root->left, key);
        else
            return searchRec(root->right, key);
    }

    // Inorder: Left - Root - Right
    void inorderRec(Node* root) {
        if (root == nullptr) return;
        inorderRec(root->left);
        cout << root->data << " ";
        inorderRec(root->right);
    }

    // Preorder: Root - Left - Right
    void preorderRec(Node* root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        preorderRec(root->left);
        preorderRec(root->right);
    }

    // Postorder: Left - Right - Root
    void postorderRec(Node* root) {
        if (root == nullptr) return;
        postorderRec(root->left);
        postorderRec(root->right);
        cout << root->data << " ";
    }

    // Find minimum value in a subtree
    Node* findMin(Node* root) {
        while (root && root->left != nullptr)
            root = root->left;
        return root;
    }

    // Recursive delete
    Node* deleteRec(Node* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->data)
            root->left = deleteRec(root->left, key);
        else if (key > root->data)
            root->right = deleteRec(root->right, key);
        else {
            // Case 1: No child (Leaf node)
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }

            // Case 2: One child
            else if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            Node* temp = findMin(root->right);
            root->data = temp->data; // Replace value
            root->right = deleteRec(root->right, temp->data);
        }
        return root;
    }

public:
    BST() { root = nullptr; }

    // Insert (iterative)
    void insert(int val) {
        Node* newNode = new Node(val);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (val < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (val < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    void inorder() { inorderRec(root); }
    void preorder() { preorderRec(root); }
    void postorder() { postorderRec(root); }
    bool search(int key) { return searchRec(root, key); }
    void deleteValue(int key) { root = deleteRec(root, key); }
};

int main() {
    BST tree;
    int num;

    cout << "Enter values to insert into BST (enter negative number to stop):\n";
    while (true) {
        cin >> num;
        if (num < 0) break;
        tree.insert(num);
    }

    cout << "\nInOrder Traversal: ";
    tree.inorder();

    cout << "\nPreOrder Traversal: ";
    tree.preorder();

    cout << "\nPostOrder Traversal: ";
    tree.postorder();

    cout << "\n\nEnter a number to search: ";
    int key;
    cin >> key;

    if (tree.search(key))
        cout << key << " is FOUND in the BST.\n";
    else
        cout << key << " is NOT found in the BST.\n";

    cout << "\nEnter a number to delete: ";
    int del;
    cin >> del;

    tree.deleteValue(del);

    cout << "\nInOrder Traversal after deletion: ";
    tree.inorder();
    cout << endl;

    return 0;
}
