#include <bits/stdc++.h>
using namespace std;

void sum_combination(int ind, int n, vector<int> a, int k, vector<int> res){
    if(ind == n){
        if(k==0){
            for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
            cout<<endl;
            return;
        }
        return;
    }
    if(k<0) return;
    res.push_back(a[ind]);
    sum_combination(ind,n,a,k-a[ind],res);
    res.pop_back();
    sum_combination(ind+1,n,a,k,res);
}

int main() {
    vector<int> a;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    vector<int> res;
    sum_combination(0,n,a,k,res);
    return 0;
}
