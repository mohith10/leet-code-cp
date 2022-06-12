// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> dp(n,0);
    vector<int> height;
    height.push_back(10);
    height.push_back(20);
    height.push_back(30);
    height.push_back(10);
    //height.push_back();
    dp[0]=0;
    
    for(int i=1;i<n;i++){
        int oneStep = dp[i-1]+abs(height[i]-height[i-1]);
        int twoStep = INT_MAX;
        if(i>1){
            twoStep = dp[i-2]+abs(height[i]-height[i-2]);
        }
        dp[i] = min(oneStep,twoStep);
    }
    cout<<dp[n-1];
    return 0;
}
