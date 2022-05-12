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
    stack<node*> s;
    node* curr = root;
    while(true){
        if(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }else{
            if(!s.empty()){
                curr = s.top();
                cout<<curr->data<<" ";
                s.pop();
                curr=curr->right;
            }
            else{
                break;
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
