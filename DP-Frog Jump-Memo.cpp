// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int f(int n, vector<int> &dp, vector<int> &height){
    if(n == 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int oneStep = f(n-1,dp,height) + abs(height[n] - height[n-1]);
    int twoStep = INT_MAX;
    if(n>1){
        twoStep = f(n-2,dp,height) + abs(height[n] - height[n-2]);
    }
    return dp[n]=min(oneStep,twoStep);
}
int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    vector<int> height;
    height.push_back(10);
    height.push_back(20);
    height.push_back(30);
    height.push_back(10);
    //height.push_back();
    f(n-1,dp,height);
    cout<<dp[n-1];
    return 0;
}
