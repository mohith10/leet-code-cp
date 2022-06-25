#include <bits/stdc++.h>
using namespace std;

void dijsktra(int source,vector<int> &dist, vector<pair<int,int>> g[], priority_queue<pair<int,int>> &pq){
    dist[source] = 0;
    pq.push({dist[source]*-1,source});
    
    while(!pq.empty()){
        int node = pq.top().second;
        int curr_dist = pq.top().first * -1;
        pq.pop();
        for(auto it:g[node]){
            if(curr_dist + it.second < dist[it.first]){
                dist[it.first] = curr_dist+it.second;
                pq.push({dist[it.first] * -1, it.first});
            }
        }
    }
}

void addEdge(int u,int v, int w,vector<pair<int,int>> g[]){
    g[u].push_back(make_pair(v,w));
    //g[v].push_back(u);
}
int main() {
    int n,source;
    cin>>n>>source;
    vector<pair<int,int>> g[n+1];
    addEdge(1,2,2,g);
    addEdge(1,4,1,g);
    addEdge(4,3,3,g);
    addEdge(2,3,4,g);
    addEdge(2,5,5,g);
    addEdge(3,5,1,g);
    priority_queue<pair<int,int>> pq;
    vector<int> dist(n+1,INT_MAX);
    dijsktra(source,dist,g,pq);
    for(int i=0;i<=n;i++){
        cout<<"From source: "<<source<<" to "<<i<<" is "<<dist[i]<<endl;
    }
    return 0;
}
