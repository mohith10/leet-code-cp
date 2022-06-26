#include <bits/stdc++.h>
using namespace std;

int parent[1e9];
int rank[1e9];

void makeSet(int n){
    for(int 0;i<=n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int node){
    if(node == parent[node]){
        return node;
    }
    
    return parent[node] = findParent(parent[node]);
}

void union(int u,int v){
    u = findParent(u);
    v = findParent(v);
    if(rank[u] < rank[v]){
        parent[u] = v;
    }else if(rank[v] < rank[u]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rank[u]++;
    }
}

int main() {
   
}
