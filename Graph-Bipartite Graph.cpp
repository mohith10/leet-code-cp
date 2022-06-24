#include <bits/stdc++.h>
using namespace std;

int bfsColoring(int node, vector<int> &color, vector<int> g[]){
    color[node] = 0;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        for(auto it:g[ele]){
            if(color[it] == -1){
                q.push(it);
                color[it] = 1-color[ele];
            }else if (color[it] == color[ele]){
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
    addEdge(2,4,g);
    addEdge(3,5,g);
    addEdge(4,6,g);
    addEdge(5,6,g);
    vector<int> color(n+1,-1);
    int flag = 0;
    for(int i=0;i<=n;i++){
        if(color[i]==-1){
            flag = bfsColoring(i,color,g);
        }
        if(flag==1){
            break;
        }
    }
    if(flag==1){
        cout<<"Not a bipartite graph";
    }else{
        cout<<"Bipartite Graph";
    }
	// your code goes here
	return 0;
}
