#include <bits/stdc++.h>
using namespace std;
int f(int ind, int buy, vector<int> &a,int n,vector<vector<int>> dp){
    if(ind == n){
        return 0;
    }
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }
    if(buy){
        return dp[ind][buy] = max(-a[ind] + f(ind+1,0,a,n,dp), f(ind+1,1,a,n,dp));
    }else{
        return dp[ind][buy] = max(a[ind] + f(ind+1,1,a,n,dp), f(ind+1,0,a,n,dp));
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    vector<vector<int>> dp(n+1,vector<int> (2,0));
    //cout<<f(0,1,a,n,dp);
    dp[n][0] = dp[n][1] = 0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy = 0;buy<=1;buy++){
            if(buy){
                dp[ind][buy] = max(-a[ind] + dp[ind+1][0], dp[ind+1][1]);
            }else{
                dp[ind][buy] = max(a[ind] + dp[ind+1][1], dp[ind+1][0]);
            }
        }
    }
    cout<<dp[0][1];
    
}
