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
 
 node* construct_bt(int inStart,int inEnd, int preStart,int preEnd,vector<int> in,vector<int>pre, map<int,int> mpp){
     if(preStart>preEnd || inStart>inEnd){
         return NULL;
     }
     
     node* ele = create_node(pre[preStart]);
     int ind = mpp[pre[preStart]];
     ele->left = construct_bt(inStart,ind-1,preStart+1,preStart + (ind-inStart),in,pre,mpp);
     ele->right = construct_bt(ind+1,inEnd,preStart+1+(ind-inStart), preEnd,in,pre,mpp);
     
     return ele;
     
 }

void inOrder(node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
 
 int main() {
 	// your code goes here
 	int n;
 	cin>>n;
 	vector<int> in,pre;
 	map<int,int> mpp;
 	for(int i=0;i<n;i++){
 	    int x;
 	    cin>>x;
 	    in.push_back(x);
 	    mpp[x] = i;
 	}
 	for(int i=0;i<n;i++){
 	    int x;
 	    cin>>x;
 	    pre.push_back(x);
 	}
 	int inStart=0,inEnd = n-1,preStart=0,preEnd = n-1;
 	node* root = construct_bt(inStart,inEnd,preStart,preEnd,in,pre,mpp);
 	inOrder(root);
 	return 0;
 }
