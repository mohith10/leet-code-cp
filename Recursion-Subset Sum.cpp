#include <bits/stdc++.h>
using namespace std;

void subset_sum(int ind, int n, vector<int> a, int sum){
    if(ind  == n){
        cout<<sum<<endl;
        return;
    }
    subset_sum(ind+1,n,a,sum + a[ind]);
    subset_sum(ind+1,n,a,sum);
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
    //vector<int> res;
    subset_sum(0,n,a,0);
    return 0;
}
