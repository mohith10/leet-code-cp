// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(vector<int> G[], vector<int> &vis){
    queue<int> q;
   q.push(1);
   vis[1] = 1;
   while(!q.empty()){
       int ele = q.front();
       q.pop();
       cout<<ele<<" ";
       for(auto it:G[ele]){
           if(!vis[it]){
               q.push(it);
               
               vis[it] = 1;
           }
           if(vis[it]){
               cout<<"Cycle Detected";
           }
       }
   }
}
void addEdge(vector<int> G[], int x,int y){
    G[x].push_back(y);
    G[y].push_back(x);
}

int main() {
    vector<int> G[6];
    addEdge(G,1,2);
    addEdge(G,1,3);
    addEdge(G,1,4);
    addEdge(G,1,5);
    addEdge(G,2,4);
    addEdge(G,2,1);
    addEdge(G,3,1);
    addEdge(G,4,1);
    addEdge(G,4,2);
    addEdge(G,5,1);
    int V=5;
    vector<int> vis(V+1,0);
    BFS(G,vis);
    return 0;
}
