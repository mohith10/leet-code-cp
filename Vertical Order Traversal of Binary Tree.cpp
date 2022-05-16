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
 void verticalTraversal(node *root){
     map<int,multiset<int>> mpp;
     queue<pair<node*,int>> q;
     if(root==NULL){
         cout<<"Empty tree";
         return;
     }
     q.push(make_pair(root,0));
     
     while(!q.empty()){
         auto temp = q.front();
         node* tempNode = temp.first;
         int level = temp.second;
         q.pop();
         mpp[level].insert(tempNode->data);
         if(tempNode->left!=NULL){
             q.push(make_pair(tempNode->left,level-1));
         }
         if(tempNode->right!=NULL){
             q.push(make_pair(tempNode->right,level+1));
         }
     }
     for(auto it:mpp){
         multiset<int> res = it.second;
         for(auto it = res.begin(); it!=res.end();it++){
             cout<<*it<<" ";
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
   verticalTraversal(root);
   
 }
