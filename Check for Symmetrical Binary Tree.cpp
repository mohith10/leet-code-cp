// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
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


bool symmetricTreeCheck(node* root1, node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)){
        return false;
    }
    
    return (root1->data == root2 ->data && symmetricTreeCheck(root1->left, root2->right) && symmetricTreeCheck(root1->right, root2->left));
}


int main() {
  struct node *root = newNode(1);
  /*root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->right->left = newNode(8);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->right->right->left = newNode(9);
  root->right->right->right = newNode(10);*/
  root->left = newNode(2);
  root->right = newNode(2);
  root->left->right = newNode(3);
  root->right->left = newNode(3);
  bool res = symmetricTreeCheck(root,root);
  if(res){
      cout<<"Symmetric";
  }else{
      cout<<"Unsymmetric";
  }
}
