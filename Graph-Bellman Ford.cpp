#include <bits/stdc++.h>
using namespace std;



void addEdge(int u,int v, int w,vector<pair<int,int>> g[]){
    g[u].push_back(make_pair(v,w));
    //g[v].push_back(u);
}
int main() {
    int n;
    cin>>n;
    vector<pair<int,int>> g[n+1];
    addEdge(0,1,5,g);
    addEdge(1,5,-3,g);
    addEdge(1,2,-2,g);
    addEdge(1,2,3,g);
    addEdge(5,3,1,g);
    addEdge(3,2,6,g);
    addEdge(3,4,-2,g);
    addEdge(2,4,3,g);
    vector<long long> dist(n+1,INT_MAX);
    vector<int> vis(n+1,0);
    
    //Bellman-Ford Algorithm
    dist[0]=0;
    for(int j=0;j<n-1;j++){
        for(int i=0;i<=n;i++){
            for(auto it:g[i]){
                if(dist[i] + it.second < dist[it.first]){
                    dist[it.first] = dist[i] + it.second;
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        cout<<"Distance from 0 to "<<i<<" is "<<dist[i]<<endl;
    }
    return 0;
}
