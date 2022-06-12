// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n>>k;
    vector<int> dp(n,0);
    vector<int> height;
    height.push_back(10);
    height.push_back(20);
    height.push_back(30);
    height.push_back(10);
    //height.push_back();
    dp[0]=0;
    
    for(int i=1;i<n;i++){
        int minStep = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int step = dp[i-j]+abs(height[i]-height[i-j]);
                minStep = min(minStep,step);
            }
            dp[i] = minStep
        }
    }
    cout<<dp[n-1];
    return 0;
}
