#include <bits/stdc++.h>
using namespace std;

void f(int ind, vector<int> a, vector<int> &res, int n){
    
    if(ind == n){
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
        return;
    }
    res.push_back(a[ind]);
    f(ind+1,a,res,n);
    
    res.pop_back();
    
    f(ind+1,a,res,n);
}

int main() {
    vector<int> a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    vector<int> res;
    f(0,a,res,n);
	return 0;
}
