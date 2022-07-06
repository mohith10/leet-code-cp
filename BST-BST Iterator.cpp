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
  class BST_Iterator{
      stack<node*> st;
    public:
        BST_Iterator(node* root){
            injector(root);
        }
    public:
        bool hasNext(){
            return !st.empty();
        }
        int next(){
            if(st.empty()){
                return -1;
            }
            node* ele = st.top();
            st.pop();
            if(ele->right){
                st.push(ele->right);
                injector(ele->right);
            }
            return ele->data;
        }
    private:
        void injector(node* pointer){
            node* curr = pointer;
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
        }
  };


  int main() {
  	node* root = create_node(1);
  	root->left = create_node(2);
  	root->right = create_node(3);
  	root->right->left = create_node(4);
  	root->right->right = create_node(5);
  	root->right->left->left = create_node(6);
  	root->right->right->right = create_node(7);
  	BST_Iterator BST (root);
  	cout<<BST.next()<<" "<<BST.next()<<" "<<BST.next();
  	return 0;
  }
