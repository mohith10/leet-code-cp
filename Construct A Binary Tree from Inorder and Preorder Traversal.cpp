// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
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
node* buildSubTree(vector<int> &preOrder, int preStart, int preEnd, vector<int> &inOrder,int inStart,int inEnd, map<int,int> &mp){
    if(preStart>preEnd || inStart > inEnd) return NULL;
    
    node* root = newNode(preOrder[preStart]);
    int elem = mp[root->data];
    int nElem = elem - inStart;
    
    root->left = buildSubTree(preOrder, preStart + 1, preStart+nElem, inOrder, inStart, elem - 1, mp);
    
    root->right = buildSubTree(preOrder, preStart+ nElem + 1, preEnd,inOrder, elem+1, inEnd, mp) ;
    
    return root;
}

node* buildTree(vector<int> &preOrder, vector<int> &inOrder, int n){
    int preStart = 0,  preEnd = n-1, inStart = 0, inEnd = n-1;
    map<int,int> mp;
   for(int i=0;i<inOrder.size();i++){
       mp[inOrder[i]] = i;
   }
   return buildSubTree(preOrder,preStart,preEnd,inOrder,inStart,inEnd,mp);
   
}

void inOrderTraversal(node* root){
    if(root == NULL) return;
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}


int main() {
  /*struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->right->left = newNode(8);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->right->right->left = newNode(9);
  root->right->right->right = newNode(10);*/
  int n;
  cin>>n;
  vector<int> preOrder, inOrder;
  for(int i=0;i<n;i++){
      int a;
      cin>>a;
      preOrder.push_back(a);
  }
  for(int i=0;i<n;i++){
      int a;
      cin>>a;
      inOrder.push_back(a);
  }
  node* root = buildTree(preOrder, inOrder,n);
  inOrderTraversal(root);
}
