#include <iostream>
 #include<vector>
 #include<queue>
 #include<map>
 using namespace std;


 struct node {
   int data;
   struct node *left, *right;
 };
 struct node *newNode(int data) {
   struct node *node = (struct node*) malloc(sizeof(struct node));
   node->data = data;
   node->left = NULL;
   node->right = NULL;

   return (node);
 }
 void allTraversal(node *root,vector<int> &preOrder,vector<int> &inOrder,vector<int> &postOrder){
     if(root==NULL){
         return;
     }
     preOrder.push_back(root->data);
     allTraversal(root->left,preOrder,inOrder,postOrder);
     inOrder.push_back(root->data);
     allTraversal(root->right,preOrder,inOrder,postOrder);
     postOrder.push_back(root->data);
 }
 int main() {
   struct node *root = newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);
   root->left->right->left = newNode(8);
   root->right->left = newNode(6);
   root->right->right = newNode(7);
   root->right->right->left = newNode(9);
   root->right->right->right = newNode(10);
   vector<int> res,preOrder,inOrder,postOrder;
   allTraversal(root,preOrder,inOrder,postOrder);
   cout<<"Pre Order ";
   for(int i=0;i<preOrder.size();i++){
       cout<<preOrder[i]<<" ";
   }
   cout<<"\nIn Order ";
   for(int i=0;i<inOrder.size();i++){
       cout<<inOrder[i]<<" ";
   }
   cout<<"\nPost Order ";
   for(int i=0;i<postOrder.size();i++){
       cout<<postOrder[i]<<" ";
   }
 }
