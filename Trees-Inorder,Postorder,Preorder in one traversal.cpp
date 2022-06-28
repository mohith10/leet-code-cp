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
 
 void traversals(Node* root){
     stack<pair<Node*,int>> st;
     st.push({root,1});
     while(!st.empty()){
         int num = st.top().second;
         Node* ele = st.top().first;
         st.pop();
         if(num == 1){
             cout<<"Preorder "<<ele->data<<endl;
             st.push({ele,num+1});
             if(ele->left){
                 st.push({ele->left,1});
             }
         }else if(num == 2){
             cout<<"Inorder "<<ele->data<<endl;
             st.push({ele,num+1});
             if(ele->right){
                 st.push({ele->right,1});
             }
         }else{
             cout<<"Postorder "<<ele->data<<endl;
         }
     }
 }

 int main(){
     Node* root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     root->right->left = newNode(6);
     traversals(root);
     return 0;
 }
