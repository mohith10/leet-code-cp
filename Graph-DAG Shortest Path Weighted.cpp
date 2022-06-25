#include <bits/stdc++.h>
using namespace std;

void topologicalSort(int node, vector<pair<int,int>> g[],stack<int> &s,vector<int> &vis){
    vis[node] = 1;
    for(auto it:g[node]){
        if(vis[it.first] == 0){
            vis[node] = 1;
            topologicalSort(it.first,g,s,vis);
        }
    }
    s.push(node);
}

void addEdge(int u,int v, int w,vector<pair<int,int>> g[]){
    g[u].push_back(make_pair(v,w));
    //g[v].push_back(u);
}
int main() {
    int n,source;
    cin>>n>>source;
    vector<pair<int,int>> g[n+1];
    addEdge(0,1,2,g);
    addEdge(0,4,1,g);
    addEdge(4,2,2,g);
    addEdge(1,2,3,g);
    addEdge(2,3,6,g);
    addEdge(4,5,4,g);
    addEdge(5,3,1,g);
    vector<int> dist(n+1,INT_MAX);
    vector<int> vis(n+1,0);
    dist[source] = 0;
    stack<int> s;
    //vector<int> topoSort;
    for(int i=0;i<=n;i++){
        if(vis[i]==0){
            topologicalSort(i,g,s,vis);
        }
    }
    
    while(!s.empty()){
        int node = s.top();
        s.pop();
        if(dist[node]!=INT_MAX){
            for(auto it:g[node]){
                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }
    
    for(int i=0;i<=n;i++){
        cout<<i<<" from source "<<source<<" "<<dist[i]<<endl;
    }
	// your code goes here
	return 0;
}
