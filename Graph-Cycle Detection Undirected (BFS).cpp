#include <bits/stdc++.h>
using namespace std;

int bfs(int node, vector<int> g[],vector<int> &vis){
    queue<pair<int,int>> q;
    vis[node] = 1;
    q.push({node,-1});
    while(!q.empty()){
        pair<int,int> head = q.front();
        q.pop();
        //cout<<head.first<<" ";
        //break;
        for(auto it:g[head.first]){
            if(vis[it]==0){
                vis[it] = 1;
                q.push({it,head.first});
            }else if(vis[it] == 1 && head.second!=it){
                return 1;
            }
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
    //addEdge(3,5,g);
    addEdge(4,6,g);
    vector<int> vis(n+1,0);
    int flag = -1;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            flag = bfs(i,g,vis);
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
