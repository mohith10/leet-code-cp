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

node* parent_link_helper(node* root, map<node*,node*> &parent_map, int target){
    queue<node*> q;
    q.push(root);
    node* res = NULL;
    parent_map[root] = NULL;
    while(!q.empty()){
        node* ele = q.front();
        if(ele->data == target) res = ele;
        q.pop();
        if(ele->left){
            parent_map[ele->left] = ele;
            q.push(ele->left);
        }
        if(ele->right){
            parent_map[ele->right] = ele;
            q.push(ele->right);
        }
    }
    return res;
}

void k_distance_node(node* start, int k,map<node*,node*> parent_map){
    map<node*,int> vis;
    queue<node*> q;
    q.push(start);
    vis[start] = 1;
    int curr = 0;
    while(!q.empty()){
        int count = q.size();
        
        if(curr == k) break;
        while(count--){
            node* ele = q.front();
            q.pop();
            if(ele->left && !vis[ele->left]){
                vis[ele->left] = 1;
                q.push(ele->left);
                
            }
            if(ele->right && !vis[ele->right]){
                vis[ele->right] = 1;
                q.push(ele->right);
                
            }
            if(parent_map[ele] && !vis[parent_map[ele]]){
                vis[parent_map[ele]] = 1;
                q.push(parent_map[ele]);
                
            }
        }
        curr++;
        
    }
    while(!q.empty()){
        cout<<q.front()->data<<" ";
        q.pop();
    }
}

int main() {
	// your code goes here
	node* root = create_node(1);
	root->left= create_node(2);
	root->right= create_node(3);
	root->left->left= create_node(4);
	root->left->right= create_node(5);
	root->right->right = create_node(6);
	map<node*,node*> parent_map;
	node* target = parent_link_helper(root,parent_map,3);
	k_distance_node(target,2, parent_map);
	return 0;
}
