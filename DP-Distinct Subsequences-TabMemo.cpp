#include <bits/stdc++.h>
using namespace std;

int f(int i,int j, vector<vector<int>> &dp,string s, string t){
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(s[i] == t[j]){
        return dp[i][j] = f(i-1,j-1,dp,s,t) + f(i-1,j,dp,s,t);
    }
    else{
        return dp[i][j] = f(i-1,j,dp,s,t);
    }
}
int main() {
	string s,t;
	getline(cin,s);
	getline(cin,t);
	int n = s.size();
	int m=t.size();
	vector<vector<int>> dp(n+1, vector<int> (m+1,0));
	//cout<<f(n-1,m-1,dp, s,t);
	//exit(0);
	for(int j=0;j<=n;j++){
	    dp[j][0] = 1;
	}
	for(int i=0;i<=m;i++){
	    dp[0][i] = 0;
	}
	dp[0][0] = 1;
	int ans = 0;
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=m;j++){
	        if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
	    }
	}
	cout<<"Longest Common Substring "<<dp[n][m];
	
    return 0;
}
