#include <stack>

void DFS(Node* root) {
    if (root == NULL)
        return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();

        cout << curr->data << " ";

        if (curr->right)
            s.push(curr->right);
        if (curr->left)
            s.push(curr->left);
    }
}
