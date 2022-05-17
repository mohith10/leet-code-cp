#include <iostream>
 #include<vector>
 #include<queue>
 #include<stack>
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
 int Diameter(node *root,bool &balance){
    if(root == NULL || !balance){
        return 0;
    }
    
    int lh = Diameter(root->left,balance);
    int rh = Diameter(root->right,balance);
    
    if(lh!=rh){
        balance = false;
    }

    return 1+max(lh,rh);

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

   
   bool res = true;
   Diameter(root,res);
   cout<<(bool)res;
   
 }
