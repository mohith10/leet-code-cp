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
 bool pathTOnode(node *root, vector<int> &path, int x){
     
     if(root==NULL){
         return false;
     }
     
     path.push_back(root->data);
     if(root->data ==x){
         return true;
     }
     
    bool res1 = pathTOnode(root->left,path,x);
    bool res2 = pathTOnode(root->right,path,x);
    if(res1 || res2)
        return true;
        
    path.pop_back();
    
    return false;
     
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
   int x;
   cin>>x;
   vector<int> res;
   pathTOnode(root,res,x);
   for(int i=0;i<res.size();i++){
       cout<<res[i]<<" ";
   }
   
 }
