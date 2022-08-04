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

void BFSListofDepth(Node* root, vector<vector<int>> &res){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> depthList;
        int queueSize = q.size();
        while(queueSize--){
            Node* frontQueue = q.front();
            q.pop();
            depthList.push_back(frontQueue->data);
            if(frontQueue->left!=NULL) q.push(frontQueue->left);
            if(frontQueue->right!=NULL) q.push(frontQueue->right);
        }
        res.push_back(depthList);
    }
}


int main() {
       Node* root = newNode(1);
	   root->left = newNode(2);
       root->right = newNode(3);
       root->left->left = newNode(4);
       root->left->right = newNode(5);
       root->left->right->left = newNode(8);
       root->right->left = newNode(6);
       root->right->right = newNode(7);
       root->right->right->left = newNode(9);
       root->right->right->right = newNode(10);
       vector<vector<int>> res;
       BFSListofDepth(root, res);
       for(int list =0;list<res.size();list++){
           for(int item = 0; item<res[list].size(); item++){
               cout<<res[list][item]<<" ";
           }
           cout<<endl;
       }
	return 0;
}
