// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int f(int ind,vector<int> &dp,vector<int> &a){
    if(ind==0){
        return a[ind];
    }
    if(ind<0){
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int select = a[ind]+f(ind-2,dp,a);
    int nonSelect = 0 + f(ind-1,dp,a);
    
    return dp[ind] = max(select,nonSelect);
}
int main() {
    int n;
    cin>>n;
    vector<int> a;
    a.push_back(3);
    a.push_back(1);
    a.push_back(2);
    vector<int> dp(n,-1);
    cout<<"Memoization "<<f(n-1,dp,a)<<endl;
    vector<int> dp_tab(n);
    dp_tab[0]=a[0];
    
    for(int i=1;i<n;i++){
        int select  = a[i];
        if(i-2>=0){
            select += dp_tab[i-2];
        }
        int nonSelect = dp[i-1];
        dp_tab[i] = max(select,nonSelect);
        
    }
    cout<<"Tabular "<<dp_tab[n-1];
    return 0;
}
