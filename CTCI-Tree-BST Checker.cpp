#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int data) {
   Node* node = new Node();
   node->data = data;
   node->left = NULL;
   node->right = NULL;

   return (node);
 }

int BST_Checker(Node* root){
    if(root==NULL) return true;
    int leftSubTree = BST_Checker(root->left);
    //if(left == INT_MIN) return INT_MIN;
    int rightSubTree = BST_Checker(root->right);
    int flag = true;
    if(root->left){
        if(root->data <= root->left->data) flag = false;
    }
    if(root->right){
        if(root->right->data < root->data) flag = false;
    }
    
    return leftSubTree & rightSubTree & flag;
    
}


int main() {
       Node* root = newNode(8);
	   root->left = newNode(3);
       root->right = newNode(10);
       root->left->left = newNode(1);
       root->left->right = newNode(6);
       root->left->right->left = newNode(4);
       root->left->right->right = newNode(7);
       
       root->right->right = newNode(14);
       root->right->right->left = newNode(13);
       cout<<BST_Checker(root);
       
	return 0;
}
