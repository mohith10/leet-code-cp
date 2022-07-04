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
 
 string serialise(node* root){
     queue<node*> q;
     string res = "";
     q.push(root);
     while(!q.empty()){
         node* ele = q.front();
         q.pop();
         if(ele==NULL){
             res=res+"*";
         }else{
             res = res + to_string(ele->data);
             q.push(ele->left);
             q.push(ele->right);
         }
     }
     return res;
 }

node* deserialise(string serialised_string){
    int i=0;
    queue<node*> q;
    int pointer = 1;
    node* d_root = create_node(serialised_string[0]-'0');
    q.push(d_root);
    while(pointer<serialised_string.size()){
        node* ele = q.front();
        q.pop();
        if(serialised_string[pointer]!='*'){
            node* temp = create_node(serialised_string[pointer]-'0');
            ele->left = temp;
            pointer++;
            q.push(temp);
        }else{
            ele->left = NULL;
            pointer++;
        }
        if(serialised_string[pointer]!='*'){
            node* temp = create_node(serialised_string[pointer]-'0');
            ele->right = temp;
            pointer++;
            q.push(temp);
        }else{
            ele->right = NULL;
            pointer++;
        }
    }
    return d_root;
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
 
 	node* root = create_node(1);
 	root->left = create_node(2);
 	root->right = create_node(3);
 	root->right->left = create_node(4);
 	root->right->right = create_node(5);
 	root->right->left->left = create_node(6);
 	root->right->right->right = create_node(7);
 	string serialised_string = serialise(root);
 	cout<<serialised_string;
 	node* d_root = deserialise(serialised_string);
 	cout<<endl;
 	inOrder(d_root);
 	return 0;
 }
