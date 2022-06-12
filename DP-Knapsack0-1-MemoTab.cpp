#include<bits/stdc++.h>
using namespace std;

int f(int ind, vector<int> &a,vector<int> &w,int W,vector<vector<int>> dp){
    if(ind==0 || W==0){
        return 0;
    }
    if(dp[ind][W]!=-1){
        return dp[ind][W];
    }
    if(w[ind] <= W){
        return dp[ind][W] = max( a[ind] + f(ind-1,a,w,W-w[ind],dp) , f(ind-1,a,w,W,dp) );
    }
    else{
        return dp[ind][W] = ( f(ind-1,a,w,W,dp) );
    }
}
int main() {
    int n,W;
    cin>>n>>W;
    vector<int> a,w;
    vector<vector<int>> dp(n+1,vector<int> (W+1,-1));
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a.push_back(x);
        w.push_back(y);
    }
    cout<<"Memoization "<<f(n-1,a,w,W,dp)<<endl;
    
    vector<vector<int>> dp_tab(n+1, vector<int> (W+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(w[i-1] <= j){
                 dp_tab[i][j] = max( a[i-1] + dp_tab[i-1][j-w[i-1]] , dp_tab[i-1][j]);
            }
            else{
                 dp_tab[i][j] = dp_tab[i-1][j];
            }
        }
    }
    cout<<"Tabular "<<dp_tab[n][W];
	return 0;
}
