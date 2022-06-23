#include <bits/stdc++.h>
using namespace std;

void bfs(int node, vector<int> g[],vector<int> &vis){
    queue<int> q;
    vis[node] = 1;
    q.push(node);
    while(!q.empty()){
        int head = q.front();
        q.pop();
        cout<<head<<" ";
        //break;
        for(auto it:g[head]){
            if(vis[it]==0){
                vis[it] = 1;
                q.push(it);
            }
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
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            //break;
            bfs(i,g,vis);
            cout<<endl;
        }
    }
	// your code goes here
	return 0;
}
