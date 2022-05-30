#include <iostream>
#include<vector>
using namespace std;

bool BiPartiteDFS(vector<int> G[], vector<int> &dfs_res, int node, vector<int> &vis){
   for(auto it : G[node]) {
            if(vis[it]==-1) {
                vis[it] = 1-vis[node];
                if(!BiPartiteDFS(G,dfs_res,it,vis)){
                    return false;
                }
            }
            else if(vis[node] == vis[it]){
                return false;
            }
   }
   return true;
}
void addEdge(vector<int> G[], int x,int y){
    G[x].push_back(y);
    //G[y].push_back(x);
}

int main() {
    vector<int> G[6];
    addEdge(G,1,2);
    addEdge(G,2,4);
    addEdge(G,2,3);
    addEdge(G,4,5);
    addEdge(G,3,5);
    addEdge(G,5,6);
    vector<int> dfs_res;
    int V=5;
    vector<int> vis(V+1,-1);
    
    for(int i=1;i<=V;i++){
        if(vis[i] == -1){
            vis[i] = 1;
            if(!BiPartiteDFS(G,dfs_res,i,vis)){
                cout<<"Not bipartite";
                exit(1);
            }
        }
    }
    cout<<"Bipartite";
    return 0;
}
