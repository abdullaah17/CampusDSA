#include <iostream>
#include <queue>
using namespace std;

// --------------------
// Node Structure
// --------------------
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// --------------------
// Inorder Traversal
// Left -> Node -> Right
// --------------------
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// --------------------
// Preorder Traversal
// Node -> Left -> Right
// --------------------
void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// --------------------
// Postorder Traversal
// Left -> Right -> Node
// --------------------
void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// --------------------
// Level Order Traversal
// Breadth First Search
// --------------------
void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left != NULL)
            q.push(curr->left);

        if (curr->right != NULL)
            q.push(curr->right);
    }
}

// --------------------
// Main Function
// --------------------
int main() {

    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\nLevel Order: ";
    levelOrder(root);

    return 0;
}
