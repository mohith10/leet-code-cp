#include <iostream>
#include<vector>
using namespace std;

void DFS(vector<int> G[], vector<int> &dfs_res, int node, vector<int> &vis){
    vis[node]=1;
    
    dfs_res.push_back(node);
 
   for(auto it : G[node]) {
            if(!vis[it]) {
                DFS(G,dfs_res,it,vis);
            }else{
                cout<<"Cycle Detected";
            }
       
   }
}
void addEdge(vector<int> G[], int x,int y){
    G[x].push_back(y);
    G[y].push_back(x);
}

int main() {
    vector<int> G[6];
    addEdge(G,1,2);
    addEdge(G,1,3);
    addEdge(G,1,4);
    addEdge(G,1,5);
    addEdge(G,2,4);
    addEdge(G,2,1);
    addEdge(G,3,1);
    addEdge(G,4,1);
    addEdge(G,4,2);
    addEdge(G,5,1);
    vector<int> dfs_res;
    int V=5;
    vector<int> vis(V+1,0);
    
    for(int i=1;i<=V;i++){
        if(!vis[i])
            DFS(G,dfs_res,i,vis);
    }
    for(int i=0;i<dfs_res.size();i++){
        cout<<dfs_res[i]<<" ";
    }
    return 0;
}
