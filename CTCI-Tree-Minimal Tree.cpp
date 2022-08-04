#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* minimalHeightTree(vector<int> arr, int begin, int end){
    if(begin>end){
        return NULL;
    }
    Node* newNode = new Node();
    int mid = begin + (end-begin)/2;
    newNode->data = arr[mid];
    newNode->left = minimalHeightTree(arr, begin, mid-1);
    newNode->right = minimalHeightTree(arr, mid+1, end);
    return newNode;
    
}

void BFS(Node *root){
    queue<Node*> q;
    if(root==NULL){
        cout<<"Empty Tree";
        return;
    }
    int ans = 0;
    q.push(root);
    
    while(!q.empty()){
        int sizeQ = q.size();
        for(int i=0;i<sizeQ;i++){
            Node* nodeTemp = q.front();
            q.pop();
            //cout<<nodeTemp->data<<" ";
            if(nodeTemp->left!=NULL){
                cout<<"left child of "<<nodeTemp->data<<" is "<<nodeTemp->left->data<<endl;
                q.push(nodeTemp->left);
            }else{
                cout<<"No left child of "<<nodeTemp->data<<" "<<endl;
            }
            if(nodeTemp->right!=NULL){
                q.push(nodeTemp->right);
                cout<<"right child of "<<nodeTemp->data<<" is "<<nodeTemp->right->data<<endl;
            }else{
                cout<<"No right child of "<<nodeTemp->data<<" "<<endl;
            }
        }
        cout<<endl;
    } 
 }

int main() {
	int n;
	cin>>n;
	vector<int> arr;
	for(int item =0 ;item < n;item++){
	    int value;
	    cin>>value;
	    arr.push_back(value);
	}
	Node* root = minimalHeightTree(arr, 0 , n-1);
	BFS(root);
	return 0;
}
