// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
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
void leftView(node *root, int level, vector<int> &res){
    if(root==NULL){
        return;
    }
    if(res.size()==level){
        res.push_back(root->data);
    }
    leftView(root->left,level+1,res);
    leftView(root->right,level+1,res);
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
  vector<int> res;
  leftView(root,0,res);
  for(int i = 0;i<res.size();i++){
      cout<<res[i]<<" ";
  }
}
