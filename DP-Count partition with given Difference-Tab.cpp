#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d,sum=0;
    cin>>n>>d;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
        sum+=x;
    }
    if((sum-d)%2!=0){
        cout<<"Not possible";
        exit(1);
    }
    int target = (sum-d)/2;
    vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
    for(int i=0;i<=target;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(a[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<"Count "<<dp[n][target];
    return 0;
}
