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
 
 node* construct_bt(int inStart,int inEnd, int postStart,int postEnd,vector<int> in,vector<int>post, map<int,int> mpp){
     if(postStart>postEnd || inStart>inEnd){
         return NULL;
     }
     
     node* ele = create_node(post[postEnd]);
     int ind = mpp[post[postEnd]];
     
     ele->left = construct_bt(inStart,ind-1,postStart,postStart + (ind-inStart)-1,in,post,mpp);
     ele->right = construct_bt(ind+1,inEnd, postStart + (ind-inStart), postEnd-1,in,post,mpp);
     
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
 	vector<int> in,post;
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
 	    post.push_back(x);
 	}
 	int inStart=0,inEnd = n-1,postStart=0,postEnd = n-1;
 	node* root = construct_bt(inStart,inEnd,postStart,postEnd,in,post,mpp);
 	inOrder(root);
 	return 0;
 }
