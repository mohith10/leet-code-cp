#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &tin, vector<int> &low, vector<int> &vis,vector<int> g[],int parent,int &timer){
    vis[node] = 1;
    timer++;
    tin[node] = low[node] = timer;
    for(auto it:g[node]){
        if(it == parent) continue;
        else if (!vis[it]){
            dfs(it,tin,low,vis,g,node,timer);
            low[node] = min(low[node],low[it]);
            if(low[it] > tin[node]){
                cout<<node<<" "<<it<<endl;
            }
        }else{
            low[it] = min (low[node],tin[it]);
        }
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
    vector<int> tin(n+1,-1);
    vector<int> low(n+1,-1);
    for(int i=0;i<=n;i++){
        if(vis[i]==0){
            dfs(i,tin,low,vis,g,-1,-1);
            cout<<endl;
        }
    }
	// your code goes here
	return 0;
}
