#include <iostream>
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

bool check_identical(node* root1,node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if((root1 == NULL && root2!=NULL ) || (root2==NULL && root1!=NULL)){
        return false;
    }
    
    return (root1->data == root2->data) && check_identical(root1->left,root2->left) && check_identical(root1->right,root2->right);
    
}
int main() {
    node* root1 = tree_start(1);
    node* root2 = tree_start(1);
    root1->left = tree_start(2);
    root2->left = tree_start(2);
    root1->right = tree_start(5);
    root2->right = tree_start(5);
    root1->left->right = tree_start(2);
    root2->left->right = tree_start(2);
    root1->left->right->left = tree_start(3);
    root2->left->right->left = tree_start(3);
    int check = check_identical(root1,root2);
    if(check){
        cout<<"Identical";
    }else{
        cout<<"Not identical";
    }
	return 0;
}
