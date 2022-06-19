#include <bits/stdc++.h>
using namespace std;

int f(int i,int j, vector<vector<int>> &dp,string s, string t){
    if(i<0 || j<0){
        return  0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(s[i] == t[j]){
        return dp[i][j] = 1+f(i-1,j-1,dp,s,t);
    }
    return dp[i][j] = max(f(i-1,j,dp,s,t),f(i,j-1,dp,s,t));
}
int main() {
	string s,t;
	getline(cin,s);
	getline(cin,t);
	int n = s.size();
	int m=t.size();
	vector<vector<int>> dp(n, vector<int> (m,0));
	for(int i=0;i<m;i++){
	    dp[0][i] = (s[0] == t[i]);
	}
	for(int i=1;i<n;i++){
	    for(int j=0;j<m;j++){
	        if(s[i] == t[j]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	    }
	}
	//cout<<f(n-1,m-1,dp, s,t);
	cout<<dp[n-1][m-1];
	return 0;
}
