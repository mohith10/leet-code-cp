// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
void generatePermutations(int ind, vector<int> &v, vector< vector<int>> &ans){
    if(ind == v.size()){
        ans.push_back(v);
        return;
    }
    for(int i=ind;i<v.size();i++){
        swap(v[ind],v[i]);
        generatePermutations(ind+1,v,ans);
        swap(v[ind],v[i]);
    }
}
int main() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
   
    vector<vector <int>> ans;
    generatePermutations(0,v,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
