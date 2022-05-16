#include <iostream>
 #include<vector>
 #include<queue>
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
 void BFS(node *root){
    if(root==NULL){
        cout<<"Empty Tree";
        return;
    }
    
    stack<node*> st1,st2;
    st1.push(root);
    while(!st1.empty() || !st2.empty()){
        while(!st1.empty()){
            node* tempNode = st1.top();
            cout<<tempNode->data<<" ";
            st1.pop();
            if(tempNode->left){
                st2.push(tempNode->left);
            }
            if(tempNode->right){
                st2.push(tempNode->right);
            }
        }
        cout<<endl;
        while(!st2.empty()){
            node* tempNode = st2.top();
            cout<<tempNode->data<<" ";
            st2.pop();
            if(tempNode->right){
                st1.push(tempNode->right);
            }
            if(tempNode->left){
                st1.push(tempNode->left);
            }
        }
        cout<<endl;
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
   
   
   BFS(root);
   
 }
