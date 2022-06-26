#include <bits/stdc++.h>
using namespace std;



void primsAlgorithm(int source,int n, vector<pair<int,int>> g[],vector<int> &key, vector<int> &mstCheck,vector<int> &parent){
    key[source] = 0;
    for(int i=0;i<n-1;i++){
        //To find min Key which is not part of MST
        int miniKey = INT_MAX,miniNode;
        for(int count =0;count<=n;count++){
            if(mstCheck[count] == 0 && key[count]<miniKey){
                miniKey = key[count], miniNode = count;
            }
        }
        //cout<<"miniNode "<<miniNode<<endl;
        mstCheck[miniNode] = 1;
        //To check all adjacent edges of miniNode
        for(auto it:g[miniNode]){
            int second_Node = it.first;
            int second_node_weight = it.second;
            if(mstCheck[second_Node] == 0 && second_node_weight<key[second_Node]){
                parent[second_Node] = miniNode;
                key[second_Node] = second_node_weight;
            }
        }
    }
}

void addEdge(int u,int v, int w,vector<pair<int,int>> g[]){
    g[u].push_back(make_pair(v,w));
    g[v].push_back(make_pair(u,w));
}
int main() {
    int n;
    cin>>n;
    vector<pair<int,int>> g[n+1];
    addEdge(0,1,2,g);
    addEdge(0,3,6,g);
    addEdge(3,1,8,g);
    addEdge(1,4,5,g);
    addEdge(1,2,3,g);
    addEdge(4,2,7,g);
    //addEdge(5,3,1,g);
    vector<int> key(n+1,INT_MAX);
    vector<int> mstCheck(n+1,0);
    vector<int> parent(n+1,-1);
    primsAlgorithm(0,n,g,key,mstCheck,parent);
	// your code goes here
	for(int i=0;i<=n;i++){
	    cout<<i<<" "<<parent[i]<<" "<<key[i]<<endl;
	}
	return 0;
}
