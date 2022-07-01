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
	root->left->right->left = create_node(6);
	root->left->right->right = create_node(7);
	root->right->right = create_node(9);
	root->right->left = create_node(8);
	stack<node*> st1;
	stack<node*> st2;
	int check = 1,first = 5,second = 3;
	path_to_node(root,st1,check,first);
	check = 1;
	path_to_node(root,st2,check,second);
	int a = st1.size();
	int b = st2.size();
	int count = abs(a-b) + 1;
	
	while(count--){
	    st1.pop();
	}
	cout<<"LCA "<<st1.top()->data;
	return 0;
}
