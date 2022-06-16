class Solution {
public:
    int f(int i,int j,int n,vector<vector<int>> &triangle,vector<vector<int>> dp){
        if(i==n-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down = f(i+1,j,n,triangle,dp);
        int right = f(i+1, j+1,n,triangle,dp);
        return dp[i][j] = triangle[i][j] + min(down,right);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp (triangle.size(),vector<int> (triangle.size(),INT_MAX));
        //return f(0,0,triangle.size(),triangle,dp);
        int n = triangle.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i+1;j++){
                if(i==0&&j==0){
                    dp[i][j] = triangle[i][j]; 
                }else{
                    int up = INT_MAX;
                    int right = INT_MAX;
                    if(i-1>-1)  up = dp[i-1][j];
                    if(j-1>-1)  right = dp[i-1][j-1];
                    dp[i][j] = triangle[i][j] + min(up,right);
                }
            }
        }
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(dp[n-1][i],mini);
        }
        return mini;
    }
};
