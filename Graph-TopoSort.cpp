#include <bits/stdc++.h>
using namespace std;

void topologicalSort(int node, vector<int> g[],stack<int> &s,vector<int> &vis){
    vis[node] = 1;
    for(auto it:g[node]){
        if(vis[it] == 0){
            vis[node] = 1;
            topologicalSort(it,g,s,vis);
        }
    }
    s.push(node);
}

void addEdge(int u,int v, vector<int> g[]){
    g[u].push_back(v);
    //g[v].push_back(u);
}
int main() {
    int n;
    cin>>n;
    vector<int> g[n+1];
    addEdge(5,0,g);
    addEdge(4,0,g);
    addEdge(5,2,g);
    addEdge(2,3,g);
    addEdge(3,1,g);
    addEdge(4,1,g);
    vector<int> vis(n+1,0);
    stack<int> s;
    vector<int> topoSort;
    for(int i=0;i<=n;i++){
        if(vis[i]==0){
            topologicalSort(i,g,s,vis);
        }
    }
    while(!s.empty()){
        topoSort.push_back(s.top());
        s.pop();
    }
    for(int i=0;i<topoSort.size();i++){
        cout<<topoSort[i]<<" ";
    }
	// your code goes here
	return 0;
}
