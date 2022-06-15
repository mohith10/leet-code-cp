class Solution {
public:
    int f(int n,int m, vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(n==0 && m==0){
            return grid[n][m];
        }
        if(n<0 || m<0){
            return INT_MAX;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        int up = f(n-1,m,grid,dp);
        int left  = f(n,m-1,grid,dp);
        return dp[n][m] = grid[n][m] + min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                }else{
                    int up = INT_MAX,left = INT_MAX;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left  = dp[i][j-1];
                   dp[i][j] = grid[i][j] + min(up,left); 
                }
            }
        }
        return dp[n-1][m-1];
    }
};
