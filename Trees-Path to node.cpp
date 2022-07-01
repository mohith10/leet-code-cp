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

void path_to_node(node* root,stack<node*> &st,int &check,int res){
    if(root==NULL){
        st.push(root);
        return;
    }
    if(check){
        st.push(root);
        //cout<<root->data<<" ";
        if(res == (root->data)){
            check = 0;
            return;
        }
        path_to_node(root->left,st,check,res);
        if(check){
            st.pop();
        }else{
            return;
        }
        path_to_node(root->right,st,check,res);
        if(check){
            st.pop();
        }else{
            return;
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
	stack<node*> st;
	int check = 1,res = 6;
	path_to_node(root,st,check,res);
	while(!st.empty()){
	    cout<<st.top()->data<<" ";
	    st.pop();
	}
	return 0;
}
