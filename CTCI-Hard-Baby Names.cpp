#include <bits/stdc++.h>
using namespace std;

pair<string,int> BFS(string root, map<string, int> &visited, map<string, int> freqTable, map<string, vector<string>> graph){
    queue<string> q;
    q.push(root);
    int count = 0;
    visited[root] = 1;
    while(!q.empty()){
        string node = q.front();
        count += freqTable[node];
        q.pop();
        vector<string> adjList= graph[node];
        for(int i=0;i<adjList.size();i++){
            if(visited[adjList[i]] == 0){
                visited[adjList[i]] = 1;
                q.push(adjList[i]);
            }
        }
    }
    return {root, count};
}

int main() {
   int i=0, size;
   cin>>size;
   map<string, int> freqTable, visited;
   while(i++ < size){
       string s;
       int freq;
       cin>>s;
       cin>>freq;
       freqTable[s] = freq;
       visited[s] = 0;
   }
   map<string, vector<string>> graph;
   int synonymSize;
   cin>>synonymSize;
   i = 0;
   while(i++ < synonymSize){
      string nodeA, nodeB;
      cin>>nodeA;
      cin>>nodeB;
      graph[nodeA].push_back(nodeB);
      graph[nodeB].push_back(nodeA);
   }
   vector<pair<string, int>> res;
   for(auto itr = freqTable.begin(); itr!=freqTable.end(); itr++){
       if(visited[itr->first] == 0){
           res.push_back(BFS(itr->first, visited, freqTable, graph));
       }
   }
   for(int i=0;i<res.size();i++){
       cout<<res[i].first<<" "<<res[i].second<<endl;
   }
}
