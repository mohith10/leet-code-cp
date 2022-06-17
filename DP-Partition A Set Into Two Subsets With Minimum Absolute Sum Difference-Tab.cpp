#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,sum=0;
    vector<int> a;
   
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
        sum+=x;
    }
    int target = sum;
    vector<vector<int>> dp(n+1, vector<int> (target + 1,0));
    for(int i=0;i<=target;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            int pick = 0;
            if(a[i-1]<j)
                dp[i][j] = dp[i-1][j - a[i-1]];
            int nonPick = dp[i-1][j];
            dp[i][j] = pick || nonPick;
        }
    }
    int mini = INT_MAX;
    for(int i = 0;i<=target;i++){
        if(dp[n][i] == 1){
            mini = min (mini, abs(sum-i));
        }
    }
    cout<<mini;
	return 0;
}
