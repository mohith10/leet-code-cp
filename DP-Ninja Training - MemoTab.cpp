#include <bits/stdc++.h>
using namespace std;

int f(int day,int lastTask, vector<vector<int>> &a, vector<vector<int>> &dp){
    if(day == 0){
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=lastTask)
                maxi = max(maxi,a[day][i]);
        }
        return dp[day][lastTask] = maxi;
    }
    if(dp[day][lastTask]!=-1){
        return dp[day][lastTask];
    }
    int maxi = 0;
    for(int i=0;i<3;i++){
        if(i!=lastTask){
            maxi =  max(a[day][i] + f(day - 1, i,a,dp),maxi);
        }
    }
    return dp[day][lastTask] = maxi;
    
}

int main() {

	int n;
	cin>>n;
	vector<vector<int>> a(n,vector<int> (3,0));
	vector<vector<int>> dp(n,vector<int> (4,-1));
	for(int i=0;i<n;i++){
	    int x,y,z;
	    cin>>x>>y>>z;
	    a[i][0] = x;
	    a[i][1] = y;
	    a[i][2] = z;
	}
	cout<<"Memoization "<<f(n-1,3,a,dp)<<endl;

	vector<vector<int>> dp_tab(n,vector<int> (4,0));
	int maxi = max(a[0][1],a[0][2]);
    dp_tab[0][0] = maxi;
    maxi = max(a[0][0],a[0][2]);
    dp_tab[0][1] = maxi;
    maxi = max(a[0][0],a[0][1]);
    dp_tab[0][2] = maxi;
    maxi = max(a[0][0],max(a[0][1],a[0][2]));
    dp_tab[0][3] = maxi;
	for(int i=1;i<n;i++){
	    for(int lastTask=0;lastTask<4;lastTask++){
	        dp_tab[i][lastTask] = 0;
	        int maxiRes=0;
	        for(int task=0;task<3;task++){
                if(lastTask!=task){
                    maxiRes =  max(a[i][task] + dp_tab[i - 1][task],maxiRes);
                }
            }
            dp_tab[i][lastTask] = maxiRes;
	    }
	}
	//maxi = max(dp_tab[n-1][0],dp_tab[n-1][1],dp_tab[n-1][2]);
	cout<<"Tabular "<<dp_tab[n-1][3];
	return 0;
}
