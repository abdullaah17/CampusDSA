#include<iostream>

using  namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree{
    Node* root;
    public:
    BinaryTree(){
        root = nullptr;
    }

    void insert(int val){
        if(root==nullptr){
            root = new Node(val);
            root->left = root->right = nullptr;
            Node*temp = new Node(v);
        }else if(val<root->data){
            root->left = insert(val,root->left);
        }else if(val>root-right)
    }

};