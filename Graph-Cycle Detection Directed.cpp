#include <bits/stdc++.h>
using namespace std;

int dfsCycle(int node, vector<int> &vis, vector<int> g[], vector<int> &dfsVis){
    vis[node] = 1;
    dfsVis[node] = 1;
    
    for(auto it:g[node]){
        if(vis[it] == -1){
           if(dfsCycle(it,vis,g,dfsVis)){
               return 1;
           }
        }else if(dfsVis[it] == 1){
            return 1;
        }
    }
    dfsVis[node] = -1;
    return 0;
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
    addEdge(3,4,g);
    //addEdge(4,1,g);
    addEdge(2,4,g);
    vector<int> vis(n+1,-1);
    vector<int> dfsVis(n+1,-1);
    int flag = 0;
    for(int i=0;i<=n;i++){
        if(vis[i]==-1){
            flag = dfsCycle(i,vis,g,dfsVis);
        }
        if(flag==1){
            break;
        }
    }
    if(flag==1){
        cout<<"Cycle exist";
    }else{
        cout<<"No Cycle";
    }
	// your code goes here
	return 0;
}
