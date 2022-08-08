#include <bits/stdc++.h>
using namespace std;

int TripleStepRecursive(int steps){
    if(steps == 0) return 1;
    
    if(steps<0) return 0;
    
    int oneStep = TripleStepRecursive(steps-1);
    int twoStep = TripleStepRecursive(steps-2);
    int threeStep = TripleStepRecursive(steps-3);
    
    return oneStep + twoStep + threeStep;
}

int TripleStepMemo(int steps, vector<int> &dp){
    if(steps == 0) return dp[steps] = 1;
    if(steps<0) return 0;
    
    if(dp[steps] !=-1) return dp[steps];
    
    return dp[steps] = TripleStepMemo(steps-1,dp) + TripleStepMemo(steps-2,dp) + TripleStepMemo(steps-3, dp);
    
}


int main() {
	int targetStep;
	cin>>targetStep;
	cout<<"Recursive Solution "<<TripleStepRecursive(targetStep)<<endl;
	vector<int> dp(targetStep + 1,-1);
	cout<<"Memoization Solution "<<TripleStepMemo(targetStep, dp)<<endl;
	vector<int> dpTable(targetStep + 1, 0);
	dpTable[0] = 1;
	for(int steps = 1; steps<=targetStep; steps++){
	    if(steps - 2 >= 0) dpTable[steps]+=dpTable[steps-2];
	    if(steps-3>=0) dpTable[steps]+= dpTable[steps-3];
	    
	    dpTable[steps]+=dpTable[steps-1];
	}
	cout<<"Tabular Solution "<<dpTable[targetStep]<<endl;
	return 0;
}
