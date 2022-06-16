class Solution {
public:
    int f(int i,int j,int n,vector<vector<int>> &matrix,vector<vector<int>> &dp){
        if(i<0 || j<0 || j>n-1){
            return INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==0){
            return matrix[i][j];
        }
        
        
        int up = f(i-1,j,n,matrix,dp);
        int right = f(i-1,j+1,n,matrix,dp);
        int left = f(i-1,j-1,n,matrix,dp);
        
        return dp[i][j] = matrix[i][j] + min (up, min(right,left));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n,vector<int> (n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    dp[i][j] = matrix[i][j];
                }
                else{
                    int up = INT_MAX, left=INT_MAX,right=INT_MAX;
                    if(i-1 > -1) up = dp[i-1][j];
                    if(i-1 > -1 && j+1 < n) right = dp[i-1][j+1];
                    if(i-1 > -1 && j-1 > -1)left = dp[i-1][j-1];
                    dp[i][j] = matrix[i][j] + min (up,min(left,right));
                }
                if(i==n-1){
                    mini = min(dp[i][j],mini);
                }
            }
        }
        return mini;
    }
};
