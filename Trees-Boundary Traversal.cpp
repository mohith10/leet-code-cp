#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};

node* tree_start(int val){
    node* new_node = new node();
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
void preorder(node* root, vector<int> &res){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right == NULL){
        res.push_back(root->data);
    }
    preorder(root->left,res);
    preorder(root->right,res);
}
void boundary_traversal(node* root, vector<int> &res){
    res.push_back(root->data);
    node* curr = NULL;
    if(root->left) curr = root->left;
    while(curr){
        if(curr->left || curr->right)res.push_back(curr->data);
        if(curr->left)curr = curr->left;
        else curr = curr->right;
    }
    preorder(root, res);
    curr = NULL;
    if(root->right) curr=root->right;
    while(curr){
        if(curr->left || curr->right) res.push_back(curr->data);
        if(curr->right)curr = curr->right;
        else curr = curr->left;
    }
    
}
int main() {
    node* root = tree_start(1);
    root->left = tree_start(2);
    root->right = tree_start(7);
    root->left->left = tree_start(3);
    root->left->right = tree_start(11);
    root->left->left->right = tree_start(4);
    root->left->left->right->left = tree_start(5);
    root->left->left->right->right = tree_start(6);
    root->right->right = tree_start(8);
    vector<int> res;
    boundary_traversal(root,res);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
	return 0;
}
