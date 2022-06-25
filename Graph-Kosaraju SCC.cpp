#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int> g[],vector<int> &vis,stack<int> &s){
    vis[node]=1;
    for(auto it:g[node]){
        if(vis[it]!=1){
            vis[it] = 1;
            dfs(it,g,vis,s);
        }
    }
    s.push(node);
}
void kosaraju(int node,vector<int> g_Trans[],vector<int> &vis){
    vis[node]=1;
    cout<<node<<" ";
    for(auto it:g_Trans[node]){
        if(vis[it]!=1){
            vis[it] = 1;
            kosaraju(it,g_Trans,vis);
        }
    }
}

void addEdge(int u,int v, vector<int> g[]){
    g[u].push_back(v);
    //g[v].push_back(u);
}
int main() {
    int n;
    cin>>n;
    vector<int> g[n+1];
    addEdge(1,2,g);
    addEdge(2,3,g);
    addEdge(3,1,g);
    addEdge(2,4,g);
    addEdge(4,5,g);
    stack<int> s;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[i]== 0){
            dfs(i,g,vis,s);
        }
    }
    vector<int> g_Trans[n+1];
    for(int i=1;i<=n;i++){
        for(auto it:g[i]){
            g_Trans[it].push_back(i);
           // cout<<i<<" "<<it<<endl;
        }
    }
    for(int i=0;i<=n;i++){
        vis[i] = 0;
    }
    while(!s.empty()){
        if(vis[s.top()] == 0){
            kosaraju(s.top(),g_Trans,vis);
            cout<<endl;
        }
        s.pop();
    }
    return 0;
}
