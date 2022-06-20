#include <bits/stdc++.h>
using namespace std;

int f(int i,int j, string s, string t,vector<vector<int>> dp){
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }
    if(dp[i][j] != -1 ){
        return dp[i][j];
    }
    if(s[i] == t[j]){
        return dp[i][j] = f(i-1,j-1,s,t,dp);
    }
    else{
        int insert =  f(i,j-1,s,t,dp);
        int deleted =  f(i-1,j,s,t,dp);
        int replace =  f(i-1,j-1,s,t,dp);
        
        return dp[i][j] = 1 + min(insert, min(deleted,replace));
    }
}
int main() {
    string s,t;
    getline(cin,s);
    getline(cin,t);
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    //cout<<f(n-1,m-1,s,t,dp);
    for(int i=0;i<=m;i++){
        dp[0][i] = i;
    }
    for(int i =0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1]){
        dp[i][j] = dp[i-1][j-1];
        }
        else{
            int insert =  dp[i][j-1];
            int deleted =  dp[i-1][j];
            int replace =  dp[i-1][j-1];
            
           dp[i][j] = 1 + min(insert, min(deleted,replace));
            }
        }
    }
    cout<<dp[n][m];
	return 0;
}
