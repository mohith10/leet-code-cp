#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};

node* tree_start(int val){
    node* new_node = new node();
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void spiral_order(node* root1){
    stack<node*> leftSpiral,rightSpiral;
    leftSpiral.push(root1);
    while(1){
        while(!leftSpiral.empty()){
            node* ele = leftSpiral.top();
            leftSpiral.pop();
            cout<<ele->data<<" ";
            if(ele->left) rightSpiral.push(ele->left);
            if(ele->right) rightSpiral.push(ele->right);
        }
        cout<<endl;
        while(!rightSpiral.empty()){
            node* ele = rightSpiral.top();
            rightSpiral.pop();
            cout<<ele->data<<" ";
            if(ele->left) leftSpiral.push(ele->left);
            if(ele->right) leftSpiral.push(ele->right);
        }
        cout<<endl;
        if(leftSpiral.empty() && rightSpiral.empty()) break;
    }
}
int main() {
    node* root1 = tree_start(1);
    root1->left = tree_start(2);
    root1->right = tree_start(3);
    root1->left->right = tree_start(4);
    root1->left->left = tree_start(5);
    spiral_order(root1);
    
	return 0;
}
