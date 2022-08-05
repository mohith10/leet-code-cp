#include <iostream>
using namespace std;
struct Node{
    int data;
    pair<int,int> childrenCount;
    Node* left;
    Node* right;
};

class RandomBST{
    Node* root;
    public:
        RandomBST(){
            root = NULL;
        }
        
        Node* insertBST(int value){
            Node* BSTiterator = root;
            Node* previous = NULL;
            char direction = 'l';
            while(BSTiterator!=NULL){
                if(value < BSTiterator->data){
                    previous = BSTiterator;
                    BSTiterator->childrenCount.first++;
                    direction = 'l';
                    BSTiterator = BSTiterator->left;
                }else{
                    previous = BSTiterator;
                    BSTiterator->childrenCount.second++;
                    direction = 'r';
                    BSTiterator = BSTiterator->right;
                }
            }
            
            Node* newNode = new Node();
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->childrenCount = {0,0};
            if(previous){
                if(direction == 'l') previous->left = newNode;
                else previous->right = newNode;
            }else{
                root = newNode;
            }
            return root;
            
        }
        Node* getRandomNode(Node* root){
            if(root == NULL){
                return NULL;
            }
            int totalSize = root->childrenCount.first + root->childrenCount.second + 1;
            //int randomIndex = (rand()%totalSize) + 1;
            int randomIndex = 4;
            cout<<"Random Node Number "<<randomIndex<<endl;
            Node* BSTiterator = root;
            while(BSTiterator!=NULL){
                if(BSTiterator->childrenCount.first + 1 == randomIndex){
                    break;
                }
                else if(BSTiterator->childrenCount.first + 1 > randomIndex){
                    cout<<"Moving left from "<<BSTiterator->data<<" ";
                    //randomIndex = (BSTiterator->childrenCount.first) - randomIndex;
                    BSTiterator = BSTiterator->left; 
                    cout<<randomIndex<<endl;
                    
                }else{
                    cout<<"Moving right from "<<BSTiterator->data<<" ";
                    randomIndex = randomIndex - (BSTiterator->childrenCount.first + 1);
                    BSTiterator = BSTiterator->right; 
                    cout<<randomIndex<<endl;
                }
            }
            return BSTiterator;
            
        }
        
        void inOrder(Node* root){
            if(root== NULL){
                return;
            }
            inOrder(root->left);
            cout<<root->data<<" "<<root->childrenCount.first<<" "<<root->childrenCount.second<<endl;
            inOrder(root->right);
        }
        
};

int main() {
	//Enter the tree
	RandomBST tree;
	Node* root = tree.insertBST(10);
	tree.insertBST(5);
	tree.insertBST(12);
	tree.insertBST(2);
	tree.insertBST(6);
	tree.insertBST(11);
	tree.insertBST(15);
	tree.insertBST(1);
	tree.inOrder(root);
	cout<<root->data;
	Node* res = tree.getRandomNode(root);
	if(res) cout<<res->data;
	
	return 0;
}
