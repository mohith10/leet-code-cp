#include <bits/stdc++.h>
  using namespace std;

  struct node{
      int data;
      node* left;
      node* right;
  };

  node* create_node(int val){
      node* new_node = new node();
      new_node->data = val;
      new_node->left = NULL;
      new_node->right = NULL;
      return new_node;
  }

  node* create_BST(vector<int> preOrder){
      node* root = create_node(preOrder[0]);
      for(int i=1;i<preOrder.size();i++){
          int data = preOrder[i];
          node* prev = NULL;
          node* curr = root;
          char last = 'l';
          while(curr){
              if(data > curr->data){
                  last = 'r';
                  prev = curr;
                  curr = curr->right;
              }else{
                  last = 'l';
                  prev= curr;
                  curr = curr->left;
              }
          }
          if(last=='l'){
              prev->left = create_node(data);
          }else{
              prev->right = create_node(data);
          }
      }
      return root;
  }
void inOrder(node* root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
  int main() {
  	/*node* root = create_node(1);
  	root->left = create_node(2);
  	root->right = create_node(3);
  	root->right->left = create_node(4);
  	root->right->right = create_node(5);
  	root->right->left->left = create_node(6);
  	root->right->right->right = create_node(7);*/
  	int n;
  	cin>>n;
  	vector<int> preOrder;
  	for(int i=0;i<n;i++){
  	    int x;
  	    cin>>x;
  	    preOrder.push_back(x);
  	}
  	node* root = create_BST(preOrder);
  	inOrder(root);
  	return 0;
  }
