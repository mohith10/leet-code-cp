#include <bits/stdc++.h>
using namespace std;

int unitWeightShortestPath(int source, vector<int> g[],vector<int> &dist,int destination){
    queue<int> q;
    q.push(source);
    dist[source] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:g[node]){
            if(dist[it] > (dist[node] + 1))
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    return dist[destination];
}

void addEdge(int u,int v, vector<int> g[]){
    g[u].push_back(v);
    g[v].push_back(u);
}
int main() {
    int n,source,destination;
    cin>>n>>source>>destination;
    vector<int> g[n+1];
    addEdge(0,1,g);
    addEdge(0,3,g);
    addEdge(1,3,g);
    addEdge(1,2,g);
    addEdge(3,4,g);
    addEdge(4,5,g);
    addEdge(5,6,g);
    addEdge(2,6,g);
    addEdge(6,7,g);
    addEdge(6,8,g);
    vector<int> dist(n+1,INT_MAX);
    cout<<unitWeightShortestPath(source,g,dist,destination);
	// your code goes here
	return 0;
}
