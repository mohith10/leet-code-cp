#include <bits/stdc++.h>
using namespace std;

//Form the graph
void addEdge(vector<int> G[], int nodeA, int nodeB){
    G[nodeA].push_back(nodeB);
    return;
}

//Find route
bool findRoute(vector<int> G[], int nodes, int source, int target, vector<int> &visited){
    if(source == target) return true;
    vector<int> iteratorList = G[source];
    for(int index = 0; index<iteratorList.size();index++){
        if(!visited[iteratorList[index]]){
            visited[iteratorList[index]] = 1;
            if(findRoute(G, nodes, iteratorList[index], target, visited)){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int nodes, edges;
    cin>>nodes>>edges;
	vector<int> G[nodes+1];
	for(int edge = 0 ; edge<edges ; edge++){
	    int nodeA, nodeB;
	    cin>>nodeA>>nodeB;
	    addEdge(G,nodeA,nodeB);
	}
	int source, target;
	cin>>source>>target;
	vector<int> visited(nodes+1,0);
	visited[source] = 1;
	bool found = findRoute(G, nodes, source, target, visited);
	if(found){
	    cout<<"Route exists";
	}else{
	    cout<<"Route doesnt exist";
	}
	return 0;
}
