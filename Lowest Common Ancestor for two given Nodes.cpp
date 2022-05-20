#include <iostream>

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
node* LCA(node *root,int x,int y){
    if( root == NULL || root->data == x || root->data==y ){
        return root;
    }
    node* left = LCA(root->left,x,y);
    node* right = LCA(root->right,x,y);
    
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    return root;
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
  int x,y;
  cin>>x>>y;
  cout<<(LCA(root,x,y))->data;
}
