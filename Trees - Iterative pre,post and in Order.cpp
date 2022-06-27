#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int value){
    Node* new_node = new Node();
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
void iterative_inorder(Node* root){
    stack<Node*> st;
    Node* ele = root;
   while(true){
       if(ele!=NULL){
           st.push(ele);
           ele = ele->left;
       }else{
           if(st.empty()) break;
           ele = st.top();
           st.pop();
           cout<<ele->data<<" ";
           ele = ele->right;
       }
    }
    cout<<endl;
}

void iterative_preorder(Node* root){
    stack<Node*> st;
    st.push(root);
    //cout<<root->data;
   while(!st.empty()){
        Node* ele = st.top();
        st.pop();
        cout<<ele->data<<" ";
        if(ele->right!=NULL) st.push(ele->right);
        if(ele->left!=NULL) st.push(ele->left);
    }
    cout<<endl;
}
void iterative_postorder(Node* root){
    stack<Node*> st;
    Node* ele = root;
    while(ele!=NULL || !st.empty()){
        if(ele!=NULL){
            st.push(ele);
            ele = ele->left;
        }else{
            Node* temp = st.top()->right;
            st.pop();
            if(temp==NULL){
                temp = st.top();
                st.pop();
                cout<<temp->data<<" ";
                while(!st.empty() && temp==st.top()->right){
                    temp = st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
                
            }else{
                ele = temp;
            }
        }
    }
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    iterative_preorder(root);
    iterative_inorder(root);
    iterative_postorder(root);
    return 0;
}
