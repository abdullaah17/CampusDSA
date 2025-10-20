#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data = val;
        left = right = NULL;
    };
};

static int index = -1;
Node* buildTree(vector<int>preorder){
    index++;
    if(preorder[index]==-1){
        return NULL;
    }
    Node* root = new Node(preorder[index]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}
int main(){
    vector <int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node*root = buildTree(preorder);
    return 0;
}