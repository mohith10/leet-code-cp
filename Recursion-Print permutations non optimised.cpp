#include <bits/stdc++.h>
using namespace std;

void permutations_extra_space(int n, vector<int> a, map<int,int> &mpp, vector<int> res){
    if(res.size() == n){
        for(int i=0;i<n;i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    for(int i=0;i<n;i++){
        if(mpp[a[i]]!=1){
            mpp[a[i]] = 1;
            res.push_back(a[i]);
            permutations_extra_space(n,a,mpp,res);
            mpp[a[i]] = 0;
            res.pop_back();
        }
    }
}

int main() {
	vector<int> a;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    int x;
	    cin>>x;
	    a.push_back(x);
	}
	map<int,int> mpp;
	vector<int> res;
	permutations_extra_space(n,a,mpp,res);
	return 0;
}
