#include <iostream>
 #include<vector>
 #include<queue>
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
 void topView(node *root){
     queue<pair<node*,int>> q;
     map <int,int> mpp;
     if(root==NULL){
         cout<<"Empty Tree";
         return;
     }
     q.push(make_pair(root,0));
     while(!q.empty()){
         auto it = q.front();
         node* temp = it.first;
         int line = it.second;
         q.pop();
         if(mpp.find(line) == mpp.end())
            mpp[line] = temp->data;
         if(temp->left!=NULL){
             q.push(make_pair(temp->left,line-1));
         }
         if(temp->right!=NULL){
             q.push(make_pair(temp->right,line+1));
         }
     }
     cout<<"Bottom view is \n";
     for(auto it:mpp){
         cout<<it.second<<" ";
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
   vector<int> res;
   topView(root);
   for(int i = 0;i<res.size();i++){
       cout<<res[i]<<" ";
   }
 }
