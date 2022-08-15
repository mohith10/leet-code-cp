#include <bits/stdc++.h>
using namespace std;

void generateDivingBoardLength(vector<int> &res, int smaller, int larger, int k, int length){
    if(k == 0){
        res.push_back(length);
        return;
    }
    generateDivingBoardLength(res, smaller, larger, k-1, length + smaller);
    generateDivingBoardLength(res, smaller, larger, k-1, length + larger);
}

int main() {
	int smaller, larger, k;
	cin>>k>>smaller>>larger;
	vector<int> res;
	generateDivingBoardLength(res, smaller, larger,k,0);
	for(int lengths = 0; lengths<res.size(); lengths++){
	    cout<<res[lengths]<<" ";
	}
	
	return 0;
}
