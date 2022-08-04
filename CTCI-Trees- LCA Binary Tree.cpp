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

Node* LCA(Node* root, int nodeA, int nodeB){
    if(root == NULL) return NULL;
      //cout<<root->data<<" ";
    if(root->data == nodeA || root->data == nodeB) return root;
  
    Node* leftSubtree = LCA(root->left, nodeA, nodeB);
    Node* rightSubtree = LCA(root->right, nodeA, nodeB);
    
    if(leftSubtree!=NULL && rightSubtree!=NULL){
        //cout<<"\n root "<<root->data<<endl;
        return root;
    }
    
    if(leftSubtree) return leftSubtree;
    else return rightSubtree;
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
       
       int nodeA, nodeB;
       cin>>nodeA>>nodeB;
       Node* result = LCA(root, nodeA, nodeB);
       cout<<result->data;
       
	return 0;
}
