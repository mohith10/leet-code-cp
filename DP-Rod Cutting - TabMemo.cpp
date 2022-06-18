#include<bits/stdc++.h>
using namespace std;
int f(int ind,vector<int> &a,int N, vector<vector<int>> &dp){
    if(ind == 0)
        return dp[ind][N] =  N*a[0];
    if(dp[ind][N]!=-1){
        return dp[ind][N];
    }
    int nonPick = f(ind-1,a,N,dp);
    int pick = -1e9;
    if(ind+1 <= N){
        pick = a[ind] + f(ind,a,N-(ind+1),dp);
    }
    
    return dp[ind][N] = max(pick,nonPick);
}
int main(){
    int n,N;
    cin>>n>>N;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    vector<vector<int>> dp(n,vector<int> (N+1,0));
    //cout<<f(n-1,a,N,dp);
    for(int i=0;i<=N;i++){
        dp[0][i] = i * a[0];
    }
    for(int i =1;i<n;i++){
        for(int j=0;j<=N;j++){
            int nonPick = dp[i-1][j];
            int pick = -1e9;
            if((i+1)<=j){
                pick = a[i] + dp[i][N-(i+1)];
            }
            dp[i][j] = max(pick,nonPick);
        }
    }
    cout<<dp[n-1][N];
    
}
