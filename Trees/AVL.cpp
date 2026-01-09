#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    int height;
};

// ************* UTILITY FUNCTIONS *************

int height(Node* n) {
    if (n == NULL)
        return 0;
    return n->height;
}

int maxVal(int a, int b) {
    return (a > b) ? a : b;
}

node* getnode(int key) {
    node* newnode = new node;
    newnode->data = key;
    newnode->left = newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

int getBalance(Node* n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

// ************* ROTATIONS *************

node* right_rotate(node* x) {                   //   x     LL Case:
    node* y = x->left;                         //   /
    node* temp = y->right;                    //   y
                                             //     \
                                            //      temp
    y->right = x;
    x->left = temp;
    //After Rotation:

    //         y
    //          \
    //           x
    //          /
    //        temp
    //

    x->height = 1 + maxVal(height(x->left), height(x->right));
    y->height = 1 + maxVal(height(y->left), height(y->right));

    return y;
}

node* left_rotate(node* x) {                   // RR Case
    node* y = x->right;
    node* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + maxVal(height(x->left), height(x->right));
    y->height = 1 + maxVal(height(y->left), height(y->right));

    return y;
}

// ************* INSERT OPERATION *************

node* insert(node* root, int k) {
    if (root == NULL)
        return getnode(k);

    if (k < root->data)
        root->left = insert(root->left, k);
    else if (k > root->data)
        root->right = insert(root->right, k);
    else
        return root; // no duplicates

    root->height = 1 + maxVal(height(root->left), height(root->right));

    int balance = getbalance(root);

    // Left Left
    if (balance > 1 && k < root->left->data)
        return right_rotate(root);

    // Right Right
    if (balance < -1 && k > root->right->data)
        return left_rotate(root);

    // Left Right
    if (balance > 1 && k > root->left->data) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // Right Left
    if (balance < -1 && k < root->right->data) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

// ************* FIND MIN VALUE NODE (SUCCESSOR) *************

node* minValueNode(node* root) {
    node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// ************* DELETE NODE *************

node* delete_node(node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = delete_node(root->left, key);

    else if (key > root->data)
        root->right = delete_node(root->right, key);

    else {
        // No child or One child
        if (root->left == NULL || root->right == NULL) {
            node* temp = (root->left) ? root->left : root->right;
            if (temp == NULL) {
                delete root;
                return NULL;
            }
            *root = *temp;
            delete temp;
        }
        else {
            // Two children: get inorder successor
            node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + maxVal(height(root->left), height(root->right));

    int balance = getbalance(root);

    // Left Left
    if (balance > 1 && getbalance(root->left) >= 0)
        return right_rotate(root);

    // Left Right
    if (balance > 1 && getbalance(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // Right Right
    if (balance < -1 && getbalance(root->right) <= 0)
        return left_rotate(root);

    // Right Left
    if (balance < -1 && getbalance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

// ************* TRAVERSALS *************

void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << "  ";
    inorder(root->right);
}

void preorder(node* root) {
    if (root == NULL) return;
    cout << root->data << "  ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "  ";
}

// ************* MAIN *************

int main() {
    node* root = NULL;
    char choice;
    int option, value;

    do {
        cout << "\n---------------- AVL TREE MENU ----------------\n";
        cout << "1. Insert\n2. Delete\n3. Inorder\n4. Preorder\n5. Postorder\n";
        cout << "-----------------------------------------------\n";
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = delete_node(root, value);
            break;

        case 3:
            inorder(root); cout << "\n";
            break;

        case 4:
            preorder(root); cout << "\n";
            break;

        case 5:
            postorder(root); cout << "\n";
            break;

        default:
            cout << "Invalid option!\n";
        }

        cout << "Press Y to continue: ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    return 0;
}