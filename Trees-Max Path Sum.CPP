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


   int max_sum_path_tree(Node* root,int &res){
      if(root==NULL){
          return 0;
      }
      int left = max(0,max_sum_path_tree(root->left,res));
      int right = max(0,max_sum_path_tree(root->right,res));
      res = max(res,root->data + left + right);
      return root->data + max(left,right);
   }
   int main(){
       Node* root = newNode(1);
       root->left = newNode(2);
       root->right = newNode(3);
       root->left->left = newNode(4);
       root->left->right = newNode(5);

       //root->right->left = newNode(6);
       int res = 0;
       max_sum_path_tree(root,res);
       cout<<"Max sum path "<<res;
       return 0;
   }
