#include<bits/stdc++.h>
 using namespace std;
 struct Node{
     int data;
     Node* left;
     Node* right;
 };

 Node* newNode(int value){
     Node* new_node = new Node();
     new_node->data = value;
     new_node->left = NULL;
     new_node->right = NULL;
     return new_node;
 }
 
 
 int depth_Tree(Node* root){
    if(root==NULL){
        return 0;
    }
    int left = 1 + depth_Tree(root->left);
    int right = 1 + depth_Tree(root->right);
    return max(left,right);
 }
 int main(){
     Node* root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     //root->right->left = newNode(6);
     cout<<depth_Tree(root);
     return 0;
 }
