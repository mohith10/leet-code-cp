#include <bits/stdc++.h>
using namespace std;

void sum_combination(int ind, int n, vector<int> a, int k, vector<int> res){
    if(k==0){
            for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
            cout<<endl;
            return;
    }
    for(int i=ind;i<n;i++){
        if(i>ind && a[i] == a[i-1]) continue;
        if(a[i]>k) break;
        res.push_back(a[i]);
        sum_combination(i+1,n,a,k-a[i],res);
        res.pop_back();
    }
    
    //sum_combination(ind+1,n,a,k,res);
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
    sort(a.begin(), a.end());
    sum_combination(0,n,a,k,res);
    return 0;
}
