#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int data) {
   Node* node = new Node();
   node->data = data;
   node->left = NULL;
   node->right = NULL;

   return (node);
 }
 
bool checker(Node* rootT1, Node* rootT2){
    if(rootT1 == NULL && rootT2 == NULL){
        return true;
    }
    if(rootT1 == NULL || rootT2 == NULL){
        return false;
    }
    
    return (rootT1->data == rootT2->data && checker(rootT1->left, rootT2->left) && checker(rootT1->right, rootT2->right));
}

bool checkSubtree(Node* root1, Node* root2){
    if(root1==NULL){
        return false;
    }
    
    if(root1->data == root2->data && checker(root1, root2)){
        return true;
    }
    bool leftResult = checkSubtree(root1->left, root2);
    if(leftResult) return true;
    bool rightResult = checkSubtree(root1->right, root2);
    
    return leftResult | rightResult;
}


int main() {
       Node* root1 = newNode(8);
	   root1->left = newNode(3);
       root1->right = newNode(10);
       root1->left->left = newNode(1);
       root1->left->right = newNode(6);
       root1->left->right->left = newNode(4);
       root1->left->right->right = newNode(7);
       root1->right->right = newNode(14);
       root1->right->right->left = newNode(13);
       
       Node* root2 = newNode(10);
       root2->right = newNode(14);
       root2->right->left = newNode(13);
       
       if(checkSubtree(root1, root2)){
           cout<<"Subtree exists";
       }else{
           cout<<"Subtree doesnt exists";
       }
       
       
       
	return 0;
}
