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

int checker(Node* root){
    if(root==NULL) return 0;
    int left = checker(root->left);
    if(left == INT_MIN) return INT_MIN;
    int right = checker(root->right);
    if(right == INT_MIN) return INT_MIN;
    if(abs(left-right)>1){
        return INT_MIN;
    }
    return max(left,right)+1;
}

bool balanceChecker(Node* root){
    if(root==NULL) return true;
    return checker(root)!=INT_MIN;
}

int main() {
       Node* root = newNode(1);
	   root->left = newNode(2);
       //root->right = newNode(3);
       root->left->left = newNode(4);
       root->left->right = newNode(5);
       root->left->right->left = newNode(8);
       root->right->left = newNode(6);
       root->right->right = newNode(7);
       root->right->right->left = newNode(9);
       root->right->right->right = newNode(10);
       cout<<balanceChecker(root);
       
	return 0;
}
