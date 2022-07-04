#include <bits/stdc++.h>
 using namespace std;

 struct node{
     int data;
     node* left;
     node* right;
 };

 node* create_node(int val){
     node* new_node = new node();
     new_node->data = val;
     new_node->left = NULL;
     new_node->right = NULL;
     return new_node;
 }
 
 void morris_inOrder(node* root){
    node* curr = root;
    while(curr){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr=curr->right;
        }else{
            node* prev = curr->left;
            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }
            
            if(prev->right==NULL){
                prev->right = curr;
                curr = curr->left;
            }else{
                prev->right = NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
    }
 }
 
 int main() {
 	node* root = create_node(1);
 	root->left = create_node(2);
 	root->right = create_node(3);
 	root->right->left = create_node(4);
 	root->right->right = create_node(5);
 	root->right->left->left = create_node(6);
 	root->right->right->right = create_node(7);
 	morris_inOrder(root);
 	return 0;
 }
