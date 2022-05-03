// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generateSubsets(int ind,vector<int> &v,vector<int> &ds, vector<vector<int>> &ans, int target){
    if(ind == v.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    if(v[ind]<=target){
        ds.push_back(v[ind]);
        generateSubsets(ind,v,ds,ans,target-v[ind]);
        ds.pop_back();
    }
    generateSubsets(ind+1,v,ds,ans,target);
    
}

int main() {
    int n,target;
    cin>>n>>target;
    vector<int> v;
    vector<int> ds;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    vector<vector<int>> ans;
    generateSubsets(0,v,ds,ans,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
