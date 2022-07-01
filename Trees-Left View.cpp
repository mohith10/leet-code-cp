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

void left_view(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int count = q.size();
        node* ele = q.front();
        q.pop();
        cout<<ele->data<<" ";
        count--;
        if(ele->left) q.push(ele->left);
        if(ele->right) q.push(ele->right);
        while(count--){
            ele = q.front();
            q.pop();
            if(ele->left) q.push(ele->left);
            if(ele->right) q.push(ele->right);
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
	left_view(root);
	return 0;
}
