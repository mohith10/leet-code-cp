#include<bits/stdc++.h>
using namespace std;
int f(int ind,vector<int> &a,int target, vector<vector<int>> &dp){
    if(ind == 0){
        if((target % a[ind]) == 0){
            return dp[ind][target] = target/a[ind];
        }
        return dp[ind][target] = 1e9;
    }
    if(dp[ind][target] !=-1){
        return dp[ind][target];
    }
    int nonPick = f(ind-1,a,target,dp);
    int pick = 1e9;
    if(a[ind] <= target)
        pick = 1+f(ind,a,target-a[ind],dp);
    //cout<<ind<<" "<<pick<<" "<<nonPick<<endl;
    return dp[ind][target] = min(pick,nonPick);
}
int main(){
    int n,target;
    cin>>n>>target;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    vector<vector<int>> dp(n,vector<int> (target+1,0));
    //cout<<"Memo "<<f(n-1,a,target,dp);
    for(int i=0;i<=target;i++){
        if(i % a[0]==0) dp[0][i] = i/a[0];
        else dp[0][i] = 1e9; 
    }
    
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=target;j++){
            int nonPick = dp[i-1][j];
            int pick = 1e9;
            if(a[i-1] <= j){
                pick = 1 + dp[i][j-a[i-1]];
            }
            
            dp[i][j] = min(pick,nonPick);
        }
    }
    
    cout<<"\nTab "<<dp[n-1][target];

    
}
