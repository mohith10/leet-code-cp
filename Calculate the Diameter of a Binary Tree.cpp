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
 int Diameter(node *root,int &diameter){
    if(root == NULL){
        return 0;
    }
    
    int lh = Diameter(root->left,diameter);
    int rh = Diameter(root->right,diameter);
    
    diameter = max(diameter,lh+rh);

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

   
   int res = 0;
   Diameter(root,res);
   cout<<res;
   
 }
