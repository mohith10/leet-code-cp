#include<bits/stdc++.h>
using namespace std;
/*
int f(int ind,vector<int> &a,int target,vector<vector<int>>dp){
    if(target==0){
        return 1;
    }
    if(ind==0){
        return 0;
    }
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }
    
    return dp[ind][target] = f(ind-1,a,target - a[ind],dp) + f(ind-1,a,target,dp);
    return dp[ind][target] =  f(ind-1,a,target,dp);
    
    
}*/
int main() {
    int n,target;
    cin>>n>>target;
    vector<int> a;
    vector<vector<int>> dp(n+1 , vector<int> (target+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=0;i<=target;i++){
        dp[0][i] = 0;
    }
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    int count = 0;
    cout<<"Memoization "<<f(n-1,a,target,dp)<<endl;
    vector<vector<int>> dp_tab(n+1 , vector<int> (target+1,0));
    for(int i=0;i<=n;i++){
        dp_tab[i][0] = 1;
    }
    for(int i=0;i<=target;i++){
        dp_tab[0][i] = 0;
    }
    dp_tab[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(a[i-1] <= j){
                dp_tab[i][j] = dp_tab[i-1][j-a[i-1]] + dp_tab[i-1][j];
            }else{
                dp_tab[i][j] = dp_tab[i-1][j];
            }
        }
    }
    cout<<dp_tab[n][target];
	return 0;
}
