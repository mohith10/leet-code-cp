#include <iostream>
#include<vector>
#include<stack>
using namespace std;

void DFS(vector<int> G[], vector<int> &dfs_res, int node, vector<int> &vis, stack<int> &st){
    vis[node]=1;
    
 
   for(auto it : G[node]) {
            if(!vis[it]) {
                DFS(G,dfs_res,it,vis,st);
            }
   }
  
   st.push(node);
}
void addEdge(vector<int> G[], int x,int y){
    G[x].push_back(y);
    //G[y].push_back(x);
}

int main() {
    vector<int> G[6];
    addEdge(G,1,2);
    addEdge(G,2,3);
    addEdge(G,2,4);
    addEdge(G,1,5);
    addEdge(G,3,5);
    
    vector<int> res;
    int V=5;
    vector<int> vis(V+1,0);
    stack<int> st;
    for(int i=1;i<=V;i++){
        if(!vis[i])
            DFS(G,res,i,vis,st);
    }
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    for(auto it:res){
        cout<<it<<" ";
    }
    
}
