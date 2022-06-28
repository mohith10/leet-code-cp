#include<bits/stdc++.h>
  using namespace std;
  struct Node{
      int data;
      Node* left;
      Node* right;
  };

  Node* newNode(int value){
      Node* new_node = new Node();
      new_node->data = value;
      new_node->left = NULL;
      new_node->right = NULL;
      return new_node;
  }


  int Balanced_Tree(Node* root){
     if(root==NULL){
         return 0;
     }
     int left = Balanced_Tree(root->left);
     if(left==-1){
         return -1;
     }
     int right = Balanced_Tree(root->right);
     if(right==-1){
         return -1;
     }
     if (abs(left-right>1)) return -1;
     return 1+max(left,right);
  }
  int main(){
      Node* root = newNode(1);
      root->left = newNode(2);
      root->right = newNode(3);
      root->left->left = newNode(4);
      root->left->right = newNode(5);
      
      //root->right->left = newNode(6);
      if(Balanced_Tree(root)!=-1){
          cout<<"BALANCED";
      }else{
          cout<<"Unbalanced";
      }
      return 0;
  }
