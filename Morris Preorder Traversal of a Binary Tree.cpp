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
void printInorder(node *root){
    
    node* curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else{
            node* prev = curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                prev = prev->right;
            }
            if(prev->right==NULL){
                prev->right = curr;
                cout<<curr->data<<" ";
                curr = curr->left;
            }else{
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
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
    printInorder(root);
}
