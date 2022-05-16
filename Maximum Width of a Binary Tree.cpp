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
 void diameterTree(node *root){
    queue<pair<node*,int>> q;
    if(root==NULL){
        cout<<"Empty Tree";
        return;
    }
    int ans = 0;
    q.push(make_pair(root,0));
    while(!q.empty()){
        int sizeQ = q.size();
        int curMin = q.front().second;
        int leftMost,rightMost;
        for(int i=0;i<sizeQ;i++){
            node* nodeTemp = q.front().first;
            
            int currId = q.front().second;
            q.pop();
            if(i==0) leftMost = currId;
            if(i==sizeQ-1) rightMost = currId;
            if(nodeTemp ->left!=NULL){
                q.push({nodeTemp->left,currId*2+1});
            }
            if(nodeTemp->right!=NULL){
                q.push({nodeTemp->right,currId*2+2});
            }
        }
        ans = max(ans, rightMost-leftMost+1);
    } 
    cout<<"Diameter "<<ans;
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
   
   
   diameterTree(root);
   
 }
