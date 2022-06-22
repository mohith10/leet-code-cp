#include <bits/stdc++.h>
using namespace std;
int f(int ind, int prev,int n,vector<int> &a,vector<vector<int>> &dp){
    if(ind  == n) return 0;
    if(dp[ind][prev+1] !=-1){
        return dp[ind][prev+1];
    }
    int len = 0 + f(ind+1, prev, n,a,dp);
    
    if(prev == -1 || a[ind]%a[prev] == 0){
        len = max(len, 1+f(ind+1, ind,n,a,dp));
    }
    return dp[ind][prev+1] = len;
}

int main() {
    int n;
    cin>>n;
    vector<int> a;
    vector<vector<int>> dp(n,vector<int> (n+1,-1));
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    cout<<f(0,-1,n,a,dp);
	// your code goes here
	return 0;
}
