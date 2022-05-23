// Online C++ compiler to run C++ program online
#include <iostream>
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
int maximumPathSum(node *root, int &res){
   if(root==NULL){
       return 0;
   }
   int leftMax = maximumPathSum(root->left,res);
   int rightMax = maximumPathSum(root->right,res);
   res = max(res, leftMax+rightMax+root->data);
   return max(leftMax, rightMax) + root->data;
    
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
  int res =0;
  maximumPathSum(root,res);
  cout<<res;
}
