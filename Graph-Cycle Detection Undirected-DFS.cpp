#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int prev, vector<int> g[],vector<int> &vis){
    vis[node] = 1;
    for(auto it:g[node]){
        if(vis[it] == 0){
            if(dfs(it,node,g,vis)){
                return 1;
            }
        }else if(it!=prev){
            return 1;
        }
    }
    return 0;
}

void addEdge(int u,int v, vector<int> g[]){
    g[u].push_back(v);
    g[v].push_back(u);
}
int main() {
    int n;
    cin>>n;
    vector<int> g[n+1];
    addEdge(1,2,g);
    addEdge(2,3,g);
    addEdge(2,7,g);
    addEdge(7,5,g);
    addEdge(3,5,g);
    addEdge(4,6,g);
    vector<int> vis(n+1,0);
    int flag = -1;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            flag = dfs(i,-1,g,vis);
            if(flag == 1){
                cout<<"Cycle Detected";
                break;
            }
        }
    }
    if(flag == 0){
        cout<<"No cycle";
    }
	// your code goes here
	return 0;
}
