// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generateSubsets(int ind,vector<int> &v,vector<int> &ds, vector<vector<int>> &ans, int target){
        if(target==0){
            ans.push_back(ds);
            return;
        }
    for(int i = ind;i<v.size();i++){
        if(i>ind && v[i] == v[i-1]){
            continue;
        }
        if(v[i]>target){
            break;
        }
        ds.push_back(v[i]);
        generateSubsets(i+1,v,ds,ans,target-v[i]);
        ds.pop_back();
    } 
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
