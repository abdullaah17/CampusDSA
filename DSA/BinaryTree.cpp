#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;
    void insert(Node*& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
            return;
        }
        if (value < node->data)
            insert(node->left, value);
        else if (value > node->data)
            insert(node->right, value);
        else
            cout << "Duplicate value ignored: " << value << endl;
    }
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }
private:
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) {
            cout << "Node with value " << value << " not found.\n";
            return node;
        }
        if (value < node->data)
            node->left = deleteNode(node->left, value);
        else if (value > node->data)
            node->right = deleteNode(node->right, value);
        else {
            if (node->left == nullptr && node->right == nullptr) {
                cout << "Deleting leaf node: " << value << endl;
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr) {
                cout << "Deleting node with one child: " << value << endl;
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                cout << "Deleting node with one child: " << value << endl;
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node* successor = findMin(node->right);
                cout << "Deleting node with two children: " << value
                    << " (Replacing with successor " << successor->data << ")\n";
                node->data = successor->data;
                node->right = deleteNode(node->right, successor->data);
            }
        }
        return node;
    }
    // BFS / Level order traversal
    void BFS(Node* node) {
        if (node == nullptr)
            return;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }

public:
    BinaryTree() { root = nullptr; }

    void insert(int value) {
        insert(root, value);
    }

    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    void displayInorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }

    void displayBFS() {
        cout << "BFS (Level Order): ";
        BFS(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
	
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Display traversals
    tree.displayInorder();
    tree.displayPreorder();
    tree.displayPostorder();
    tree.displayBFS();

    cout << "\nDeleting 20 (leaf node)::\n";
    tree.deleteValue(20);
    tree.displayInorder();

    cout << "\nDeleting 30 (node with one child)::\n";
    tree.deleteValue(30);
    tree.displayInorder();

    cout << "\nDeleting 50 (node with two children)::\n";
    tree.deleteValue(50);
    tree.displayInorder();

    return 0;
}
