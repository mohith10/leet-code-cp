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

void top_view(node* root){
    map<int,vector<int>> m;
    queue<pair<node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        node* ele = q.front().first;
        int counter = q.front().second;
        q.pop();
        if(m[counter].size()==0)m[counter].push_back(ele->data);
        if(ele->left){
            q.push({ele->left,counter-1});
        }
        if(ele->right){
            q.push({ele->right,counter+1});
        }
    }
    for(auto it:m){
        for(int i=0;i<it.second.size();i++){
            cout<<it.second[i]<<" ";
        }
    }
}

int main() {
	// your code goes here
	node* root = create_node(1);
	root->left= create_node(2);
	root->right= create_node(3);
	root->left->left= create_node(4);
	root->left->right= create_node(5);
	root->right->right = create_node(6);
	top_view(root);
	return 0;
}
