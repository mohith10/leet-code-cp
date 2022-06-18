#include<bits/stdc++.h>
using namespace std;
int f(int ind,vector<int> &a,int target, vector<vector<int>> &dp){
    if(ind == 0){
        if((target % a[ind]) == 0){
            return dp[ind][target] = 1;
        }
        return dp[ind][target] = 0;
    }
    if(dp[ind][target] !=-1){
        return dp[ind][target];
    }
    int nonPick = f(ind-1,a,target,dp);
    int pick =0;
    if(a[ind] <= target)
        pick = f(ind,a,target-a[ind],dp);
    //cout<<ind<<" "<<pick<<" "<<nonPick<<endl;
    return dp[ind][target] = (pick+nonPick);
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
        dp[0][i] = (i % a[0]==0);
    }
    
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=target;j++){
            int nonPick = dp[i-1][j];
            int pick = 0;
            if(a[i] <= j){
                pick =  dp[i][j-a[i]];
            }
            //cout<<i<<" "<<j<<" "<<pick<<" "<<nonPick<<endl;
            dp[i][j] = pick+nonPick;
        }
    }
    
    cout<<"\nTab "<<dp[n-1][target];

    
}
