#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    int leftChildren = 0;
    Node* left = NULL;
    Node* right = NULL;
};

Node* BST_Insertion(int value, Node* root){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->leftChildren = 0;
    if(root == NULL){
        root=newNode;
        return root;
    }
    Node* treeIter = root;
    Node* prev = NULL;
    char direction = 'l';
    while(treeIter != NULL){
        prev = treeIter;
        if(value <= treeIter->data){
            treeIter->leftChildren = treeIter->leftChildren + 1;
            cout<<"For "<<value<<" "<<treeIter->data<<" "<<treeIter->leftChildren<<endl;
            direction = 'l';
            treeIter=treeIter->left;
        }else{
            direction = 'r';
            treeIter = treeIter->right;
        }
    }
    if(direction == 'l'){
        prev->left = newNode;
    }else{
        prev->right = newNode;
    }
    return root;
}

int rankHelper(Node* root, int value){
    if(root==NULL){
        return 0;
    }
    if(value == root->data){
        return root->leftChildren;
    }else if (value < root->data){
        return rankHelper(root->left, value);
    }else{
        return root->leftChildren + 1 + rankHelper(root->right,value);
    }
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" "<<root->leftChildren<<endl;
    inorder(root->right);
}

int main() {
	int num, query;
	cin>>num>>query;
	Node* root = NULL;
	for(int item = 0; item<num;item++){
	    int ele;
	    cin>>ele;
	    root = BST_Insertion(ele,root);
	}
	cout<<"Inorder "<<endl;
	inorder(root);
	int res  = rankHelper(root, query);
    cout<<res;
	return 0;
}
