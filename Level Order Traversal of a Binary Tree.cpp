#include <iostream>
 #include<vector>
 #include<queue>
 #include<map>
 #include<set>
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
    queue<node*> q;
    if(root==NULL){
        cout<<"Empty Tree";
        return;
    }
    int ans = 0;
    q.push(root);
    while(!q.empty()){
        int sizeQ = q.size();
        for(int i=0;i<sizeQ;i++){
            node* nodeTemp = q.front();
            q.pop();
            cout<<nodeTemp->data<<" ";
            if(nodeTemp->left!=NULL){
                q.push(nodeTemp->left);
            }
            if(nodeTemp->right!=NULL){
                q.push(nodeTemp->right);
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
