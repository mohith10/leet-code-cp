#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* new_node(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void level_order(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int count = q.size();
        while(count--){
            Node* ele = q.front();
            q.pop();
            if(ele->left){
                q.push(ele->left);
            }
            if(ele->right){
                q.push(ele->right);
            }
            cout<<ele->data<<" ";
        }
        cout<<endl;
    }
}


int main() {
      Node* root = new_node(1);
      root->left = new_node(2);
      root->right = new_node(3);
      root->left->left = new_node(4);
      root->left->right = new_node(5);
      root->left->right->left = new_node(8);
      root->right->left = new_node(6);
      root->right->right = new_node(7);
      root->right->right->left = new_node(9);
      root->right->right->right = new_node(10);
      level_order(root);
}
