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

node* lca_tree(node* root,int first, int second){
    if(root==NULL || root->data == first || root->data == second){
        return root;
    }
    auto left  = lca_tree(root->left,first,second);
    auto right = lca_tree(root->right,first, second);
    
    if(left == NULL) return right;
    if(right == NULL) return left;
    else return root;
}

int main() {
	// your code goes here
	node* root = create_node(1);
	root->left= create_node(2);
	root->right= create_node(3);
	root->left->left= create_node(4);
	root->left->right= create_node(5);
	root->left->right->left = create_node(6);
	root->left->right->right = create_node(7);
	root->right->right = create_node(9);
	root->right->left = create_node(8);
	int first = 4,second  = 5;
	cout<<"LCA "<<lca_tree(root,first,second)->data;
	return 0;
}
