#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> g[],vector<int> &vis){
    queue<int> q;
    vis[node] = 1;
    cout<<node<<" ";
    for(auto it:g[node]){
        if (vis[it] == 0) dfs(it,g,vis);
    }
    
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
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            //break;
            dfs(i,g,vis);
            cout<<endl;
        }
    }
	// your code goes here
	return 0;
}
