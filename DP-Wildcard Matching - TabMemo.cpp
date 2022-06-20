#include <bits/stdc++.h>
using namespace std;

int f(int i,int j, string s, string t,vector<vector<int>> dp){
    if(i<0 && j<0){
        return true;
    }
    if(i<0 && j>=0){
        return false;
    }
    if(j<0 && i>=0){
        for(int ii=i;ii>=0;ii--){
            if(s[ii]!='*'){
                return  false;
            }
        }
        return true;
    }
    if(dp[i][j] != -1 ){
        return dp[i][j];
    }
    if(s[i] == '?' || s[i] == t[j]){
        return dp[i][j] = f(i-1,j-1,s,t,dp);
    }
    else{
        if(s[i]=='*'){
            return dp[i][j] = f(i-1,j,s,t,dp) | f(i,j-1,s,t,dp) ;
        }
        else return dp[i][j] = false;
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
    //exit(1);
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    for(int i =1;i<=n;i++){
        bool flag = true;
        for(int ii=1;i<=i;i++){
            if(s[i]!='*'){
                flag = false;
                break;
            };
        }
        dp[i][0] = flag;
    }
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i] == '?' || s[i] == t[j]){
                dp[i][j] = dp[i-1][j-1];
        }
        else{
            if(s[i]=='*'){
                 dp[i][j] = dp[i-1][j] | dp[i][j-1] ;
            }
            else  dp[i][j] = false;
        }
        }
    }
    cout<<dp[n][m];
	return 0;
}
