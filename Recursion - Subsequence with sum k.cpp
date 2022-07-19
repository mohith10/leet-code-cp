#include <bits/stdc++.h>
using namespace std;

void print_subsequence_sum_k(vector<int> a,int k, int n, int ind, vector<int> res){
    if(k==0){
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(ind==n){
        return;
    }
    print_subsequence_sum_k(a,k,n,ind+1,res);
    if(a[ind]<=k){
        res.push_back(a[ind]);
        print_subsequence_sum_k(a,k-a[ind],n,ind+1,res);
        res.pop_back();
    }
}

int main() {
	// your code goes here
	vector<int> a;
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
	    int x;
	    cin>>x;
	    a.push_back(x);
	}
	vector<int> res;
	print_subsequence_sum_k(a,k,n,0,res);
	return 0;
}
